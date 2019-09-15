// Alejandro Orpi Sept 2019
// Calculates the first point of collision of a circle thrown with configurable parameters over a flat ground

#include "pch.h"
#include "Circle.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T = float, typename enable_if<is_arithmetic<T>::value>::type* = nullptr>
T RequestInputData(string prompt)
{
	bool retry = true;
	T input;
	while(retry)
	{
		cout << prompt << "\n";
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Could not parse the " << typeid(T).name() << " parameter, please type valid input.\n";
		}
		else
			retry = false;
	}
	return input;
}

template<typename T = float, typename enable_if<is_arithmetic<T>::value>::type* = nullptr>
T RequestInputDataGEThan(string prompt, int compareTo = 0)
{
	T validInput = compareTo - 1;
	do
	{
		T input = RequestInputData(prompt);
		if (input < compareTo)
			cout << "Input value is not greater than 0. Please type a greater than 0 value.\n";
		else
			validInput = input;
	} while (validInput < compareTo);
	return validInput;
}

// Why smart pointers? I prefer to avoid c style pointers, but a program this simple could use it with no problems
// Why unique_ptr? because this program as is can only calculate a single circle
unique_ptr<Circle> RequestInput()
{
	cout << "Welcome! This program will calculate the collision points of a circle in a flat ground\n";
	float xVelocity = RequestInputData("Type the circle initial x velocity:");
	float yVelocity = RequestInputDataGEThan("Type the circle initial y velocity (equal or over zero):");
	float xPosition = RequestInputData("Type the circle initial x position:");
	float yPosition = RequestInputDataGEThan("Type the circle initial y position (equal or over zero):");
	float friction = RequestInputDataGEThan("Friction (non negative, 0 for no friction, high numbers for lots of friction):");
	return make_unique<Circle>(Vector2(xVelocity, yVelocity), Vector2(xPosition, yPosition), friction);
}

int main()
{
	auto circle = RequestInput();
	int reboundsToCalculate = RequestInputDataGEThan<int>("Rebounds to calculate", 1);
	cout << "The circle will hit these positions: \n";
	cout << "Starting at: " << circle->GetPosition().ToString() << "\n";
	for (int i = 0; i < reboundsToCalculate; i++)
	{
		circle->FindNextCollisionPoint();
		cout << "Collision at: " << circle->GetPosition().ToString() << "\n";
	}
}