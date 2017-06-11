#ifndef Dice_Roller_HPP
#define Dice_Roller_HPP

#include <random>
#include <map>
#include <memory>
#include <string>
#include <cmath>
using numType = unsigned int;
using distributer = std::uniform_int_distribution<numType>;

class DiceRoller 
{
	std::default_random_engine randomEngine;
	std::map<numType, distributer> distributerMap;
	DiceRoller()
	{
		std::random_device randomSeed;
		randomEngine.seed(randomSeed());
	}
public:
	static std::string generateNumbers(numType numOfSides, numType numOfDice)
	{
		//todo: handle the values 1 and 0
		if (numOfSides < 2 || numOfDice == 0)
			return std::string("Invalid numbers");

		//create one dice roller
		static std::unique_ptr<DiceRoller> _instance(new DiceRoller);

		//Make a distibuter if needed
		if (_instance->distributerMap.find(numOfSides) == _instance->distributerMap.end())
		{
			_instance->distributerMap[numOfSides] = distributer(1, numOfSides);
		}
		numType totals = 0;
		numType temp = 0;
		std::string outputString;
		outputString.append("Roll: ");
		for (numType numOfRolls = 0; numOfRolls < numOfDice; ++numOfRolls)
		{
			temp = _instance->distributerMap[numOfSides](_instance->randomEngine);
			
			if (numOfRolls == numOfDice - 1 && numOfDice != 1)
			{
				outputString.append(" and ");
			}
			else if(numOfRolls != 0)
			{
				outputString.append(", ");
			}
			outputString.append(std::to_string(temp));
			totals += temp;
		}
		outputString.append("\nTotal: " + std::to_string(totals));

		return outputString;
	}

};


#endif // !Dice_Roller_HPP
