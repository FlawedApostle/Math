#pragma once
#include "Vector3.h"
#include <cmath>
#include <math.h>
#include <string>
class Vector3
{
private:
protected:
	float x, y, z;
	void setVector3(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}


public:
	// default
	Vector3()
	{
		setVector3(0,0,0);
	}

	Vector3(float x, float y, float z)
	{
		setVector3(x, y, z);
	}

	Vector3(Vector3& a)
	{
		setVector3(a.x, a.y, a.z);
	}
	~Vector3();
	void printW(std::string note);
	void print(std::string note);
	void print();

	// setters
	float setVector3x(float set);
	float setVector3y(float set);
	float setVector3z(float set);
	void setVector3xyz(Vector3 v);
	
	 
	// getters 
	Vector3& getVector3();
	float const getVector3x();
	float const getVector3y();
	float const getVector3z();
	Vector3 const getVectorxyz();
	 


	Vector3& operator = (Vector3 v);
	Vector3& operator + (const Vector3 v);
	Vector3& operator + (const float s);
	Vector3& operator - (const Vector3 v);
	Vector3& operator * (const float scalar);
	Vector3& operator * (const Vector3& v);


	Vector3& normalize(Vector3& a);
	Vector3& crossProduct(Vector3& a, Vector3& b);
	float DotProduct(Vector3& a, Vector3& b);
	float magnitude(Vector3& a);


};