#include "pch.h"
#include <math.h>
#include "Circle.h"
#include "Constants.h"


Circle::~Circle()
{
}

void Circle::FindNextCollisionPoint()
{
	// The collision point will be at the starting position (0) plus velocity per time spent flying before the first collision
	float timeFlying = TimeForCollision();
	// x = v * t
	position.x += velocity.x * timeFlying;
	position.y = 0;
	velocity *= frictionCoefficient;
}

float Circle::TimeForCollision() const
{
	// Time for collision is the time it takes for the circle to reach velocity.y = 0 plus going back to the ground
	float endVelocity = 0;

	// t = velocity delta / gravity
	float timeForVelocityY0 = (endVelocity - velocity.y) / GRAVITY;

	// To go back to the ground, we need to find out how high are we now, so lets use the previous time
	// currentY = initialY + initialVelocity * time + 1 / 2 * gravity * time^2
	float highestHeight = position.y + velocity.y * timeForVelocityY0 + 0.5f * GRAVITY * timeForVelocityY0 * timeForVelocityY0;

	// Now lets just find out how long it takes to go back to the ground from here
	// y = 1 / 2 * gravity * time^2 previous formula but many things zeroed out
	// t = sqrt(2 * y / gravity) rearranged to solve for t 
	float timeToGround = sqrtf(2 * highestHeight / -GRAVITY);

	return timeForVelocityY0 + timeToGround;
}