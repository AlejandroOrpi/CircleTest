#include "pch.h"
#include "Vector2.h"

const Vector2& Vector2::operator*=(const float multiplier)
{
	x *= multiplier;
	y *= multiplier;
	return *this;
}
