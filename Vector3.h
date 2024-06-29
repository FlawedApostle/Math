#pragma once
#include "Vector3.h"
#include <cmath>
#include <math.h>
class Vector3
{
private:
protected:
	float x, y, z;
	float w;
	void setVector3(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
	// Setting w value
	void setVector3(float x_, float y_, float z_ ,float w_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}

public:

	Vector3()
	{
		setVector3(1,1,1);
	}

	Vector3(float x, float y, float z)
	{
		setVector3(x, y, z);
	}

	
	Vector3(float x, float y, float z, float w)
	{
		setVector3(x, y, z , w);
		//setVector3w(w);
	}

	Vector3(Vector3& a)
	{
		setVector3(a.x, a.y, a.z);
		if (w != NULL)
		{
			w = a.w;
		}
	}
	~Vector3();
	void printW(std::string note);
	void print(std::string note);
	void print();

	Vector3& getVector3();
	float setVector3x(float set);
	float setVector3y(float set);
	float setVector3z(float set);
	float setVector3w(float set);
	float getVector3x();
	float getVector3y();
	float getVector3z();
	float getVector3w();


	Vector3& operator = (const Vector3& v);
	Vector3& operator + (const Vector3& v);
	Vector3& operator - (const Vector3& v);
	Vector3& operator * (const float scalar);


	Vector3& normalize(Vector3& a);
	Vector3& crossProduct(Vector3& a, Vector3& b);
	float DotProduct(Vector3& a, Vector3& b);
	float magnitude(Vector3& a);


};