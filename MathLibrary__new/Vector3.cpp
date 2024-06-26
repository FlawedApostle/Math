#include <iostream>
#include "Quat.h"



//Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
//{
//
//}
Vector3::~Vector3()
{
}

void Vector3::printW(std::string note)
{
	std::cout << note;
	printf("(%f,%f,%f) (w = %f)\n", x, y, z, w);
}
void Vector3::print(std::string note)
{
	std::cout << note;
	//printf("(%f,%f,%f) (w = %f)\n", x, y, z, w);
	printf("(%f,%f,%f)\n", x, y, z);
}
void Vector3::print()
{
	printf("(%f,%f,%f)\n", x, y, z);
}

Vector3& Vector3::getVector3()
{
	Vector3 ijk(getVector3x(), getVector3y(), getVector3z() , getVector3w());
	return ijk;
}
float Vector3::setVector3x(float set)
{
	x = set;
	return x;
}
float Vector3::setVector3y(float set)
{
	y = set;
	return y;
}
float Vector3::setVector3z(float set)
{
	z = set;
	return z;
}
float Vector3::setVector3w(float set)
{
	w = set;
	return w;
}

float Vector3::getVector3x()
{
	return x;
}
float Vector3::getVector3y()
{
	return y;
}
float Vector3::getVector3z()
{
	return z;
}
// Depth Of Field Coord
float Vector3::getVector3w()
{
	return w;
}

Vector3& Vector3::operator=(const Vector3& v)
{
	setVector3(v.x, v.y, v.z); return *this;
}

Vector3& Vector3::operator+(const Vector3& v)
{
	x = v.x + x;
	y = v.y + y;
	z = v.z + z;
	return *this;
}

Vector3& Vector3::operator-(const Vector3& v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;

	Vector3 ijk(x, y, z);
	return ijk;
}

Vector3& Vector3::operator*(const float scalar)
{
	x = scalar * x;
	y = scalar * y;
	z = scalar * z;

	Vector3 ijk(x, y, z);
	return ijk;

}

Vector3& Vector3::operator*(const Vector3& v)
{
	x = x * v.x;
	y = y * v.y;
	z = z * v.z;
	Vector3 ijk(x, y, z);
	return ijk;

}

// Perpendicular Cross Product 2D
/*
	*I want to add a 2D cross product, 
	*to divide a 3D Vector by w (depth value) will yeild a 2D vector
	*That 2D vector I then want to use for a 2D cross product function
	*					a X b = (ax)(by) - (ay)(bx)
*/

Vector3& Vector3::normalize(Vector3& a)
{
	float magA = magnitude(a);
	float i = a.x / magA;
	float j = a.y / magA;
	float k = a.z / magA;

	Vector3 ijk(x=i,y=j,z=k);
	return ijk;
}

Vector3& Vector3::crossProduct(Vector3& a, Vector3& b)
{
	//			i	-	j	  +		k
	//			ax		ay			az
	//			bx		by			bz
	//			(ay*bz)-(az*by)i
	//			(ax*bz)-(az*bx)j
	//			(ax*by)-(ay*bx)k

	float i = (a.y*b.z)-(a.z*b.y);
	float j = (a.x*b.z)-(a.z*b.x);
	float k = (a.x*b.y)-(a.y*b.x);
	x = i;
	y = j;
	z = k;
	
	Vector3 ijk(setVector3x(x) , setVector3y(y), setVector3z(z));
	return ijk;
}

float Vector3::DotProduct(Vector3& a, Vector3& b)
{
	// Dot Prod
	//				i		j		k
	//				a.x		a.y		a.z		b.x
	//										b.y
	//										b.z
	//				(a.x*b.x)+(a.y*b.y)+(a.z*b.z)

	float i = a.x * b.x;
	float j = a.y * b.y;
	float k = a.z * b.z;
	x = i;
	y = j;
	z = k;
	float ijk = x + y + z;
	return ijk;
}

float Vector3::magnitude(Vector3& a)
{
	float i = pow(a.x, 2);
	float j = pow(a.y, 2);
	float k = pow(a.z, 2);
	float ijk = i + j + k;
	float sqrtIJK = sqrt(ijk);
	
	return sqrtIJK;
}




