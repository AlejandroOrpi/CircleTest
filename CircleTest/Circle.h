#pragma once
#include "Vector2.h"


class Circle
{
public:
	Circle(Vector2 initialVelocity, Vector2 initialPosition, float friction) : velocity(initialVelocity), position(initialPosition), frictionCoefficient(1/(friction + 1)) {}
	~Circle();

	const Vector2& GetPosition() const { return position; }
	void FindNextCollisionPoint();

private:
	Vector2 velocity;
	Vector2 position;
	float frictionCoefficient;

	float TimeForCollision() const;
};

