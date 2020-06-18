#include "Vec2.h"

Vec2::Vec2(float in_x, float in_y)
	://class initializer list
	x( in_x ),
	y( in_y )
{
	////OR
	////x = in_x;
	////y = in_y;
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y+ rhs.y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x*rhs, y* rhs);
}

Vec2& Vec2::operator*=(float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
