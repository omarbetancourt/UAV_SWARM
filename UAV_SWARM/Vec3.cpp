#include "Vec3.h"
#include <cmath>
Vec3::Vec3(float in_x, float in_y, float in_z)
	://class initializer list
	x(in_x),
	y(in_y),
	z(in_z)
{
}

float Vec3::mag(const Vec3& p1, const Vec3& p2) const
{
	const Vec3 dist = p2 - p1;
	return sqrt((pow(dist.x, 2.0f) + pow(dist.y, 2.0f) + pow(dist.z, 2.0f)));
}

Vec3 Vec3::operator+(const Vec3& rhs) const
{
	return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vec3& Vec3::operator+=(const Vec3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vec3 Vec3::operator*(float rhs) const
{
	return Vec3(x * rhs, y * rhs, z * rhs);
}

Vec3& Vec3::operator*=(float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

Vec3 Vec3::operator/(float rhs) const
{
	return Vec3(x / rhs, y / rhs, z / rhs);
}

Vec3& Vec3::operator/=(float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

Vec3 Vec3::operator-(const Vec3& rhs) const
{
	return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vec3& Vec3::operator-=(const Vec3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}