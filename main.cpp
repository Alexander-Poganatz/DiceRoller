#include "DiceRoller.hpp"

#include <iostream>
int main()
{
	std::cout << "Welcome to the Dice Roller. " << std::endl;
	std::cout << "Usage: NumOfSides NumOfRolls " << std::endl;
	std::cout << "Entering a value with x will exit " << std::endl;

	std::string input;

	bool notQuiting = true;
	while (notQuiting)
	{
		
		////////////////////////////
		//Start getting input
		////////////////////////////
		std::getline(std::cin, input);

		if (input.empty())
			continue;

		//Check to exit
		for (auto iter = input.begin(); iter != input.end(); ++iter)
		{
			if (tolower(*iter) == 'x')
				notQuiting = false;
		}
		if (!notQuiting)
			break;

		//Check for invalid input
		for (auto iter = input.begin(); iter != input.end(); ++iter)
		{
			if (!isdigit(*iter) || *iter != ' ')
				continue;
		}
		auto stringPointer = input.begin();
		//Get to the first digit.
		for (; stringPointer != input.end() && !isdigit(*stringPointer); ++stringPointer);

		//Check to make sure a digit exists
		if (stringPointer == input.end())
			continue;

		int firstNumberDigitOffset = stringPointer - input.begin();
		int whiteSpaceAfterFirstDigit = input.find(' ', firstNumberDigitOffset);
		
		//There is only one number
		if (whiteSpaceAfterFirstDigit == std::string::npos)
			continue;

		std::string firstNum(input.substr(firstNumberDigitOffset, whiteSpaceAfterFirstDigit - firstNumberDigitOffset));

		int secondNumOffset;
		//Get to the second number
		for (secondNumOffset = whiteSpaceAfterFirstDigit; secondNumOffset < input.size() && !isdigit(input[secondNumOffset]); ++secondNumOffset);

		//There is no second number :o
		if (secondNumOffset == input.size())
			continue;

		int lastDigit;
		for (lastDigit = secondNumOffset; lastDigit < input.size() && isdigit(input[lastDigit]); ++lastDigit);
		
		std::string secondNum(input.substr(secondNumOffset, lastDigit - secondNumOffset));

#ifdef _DEBUG
		std::cout << "First Num: [" << firstNum << "] Second Num: [" << secondNum << "]" << std::endl;
#endif // DEBUG

		////////////////////////////
		//End getting input
		////////////////////////////

		std::cout << DiceRoller::generateNumbers(std::stoi(firstNum), std::stoi(secondNum)) << std::endl;
	}
}

