#pragma once

class Vec3
{
public:
	Vec3() = default; // do nothing constructor
	Vec3(float in_x, float in_y, float z);

	float mag(const Vec3& p1, const Vec3& p2) const;

	Vec3 operator+(const Vec3& rhs) const; // lhs + rhs
	Vec3& operator+=(const Vec3& rhs);

	Vec3 operator*(float rhs) const;
	Vec3& operator*=(float rhs);

	Vec3 operator/(float rhs) const;
	Vec3& operator/=(float rhs);

	Vec3 operator-(const Vec3& rhs) const;
	Vec3& operator-=(const Vec3& rhs);

public:
	float x;
	float y;
	float z;
};