#pragma once

#include <string>
#include <sstream>

class Vector2
{
public:
	Vector2(float x, float y) : x(x), y(y) {}
	Vector2(const Vector2& v2) : Vector2(v2.x, v2.y) {}

	float x, y;

	const Vector2& operator*= (const float multiplier);

	std::string ToString() const
	{
		std::stringstream ss;
		ss << "X: " << x << ", Y: " << y;
		//return ss;
		return ss.str();
	}
};

