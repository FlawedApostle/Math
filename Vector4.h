#pragma once
#include "string.h"
#include "Vector3.h"
//#include "atlstr.h"			// CString
class Vector3;
class Quaternion;
class Vector4
{
protected:
	float x, y, z, w;
	float setVector4(float x_, float y_, float z_, float w_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = w_;

		return x, y, z, w;
	}
public:

	Vector4() {};
	Vector4(float x_, float y_, float z_, float w_) 
	{
		setVector4(x_, y_, z_, w_);
	}
	Vector4(Vector3& v) 
	{
		x = v.getVector3x();
		y = v.getVector3y();
		z = v.getVector3z();
		w = 0;
	}
	~Vector4() {};
	void print(std::string note)
	{
		std::cout << note;
		printf(" Vector4 = [%f,%f,%f,%f]\n", x, y, z, w);
	}
	void print()
	{	
		printf("Vector4 = [%f,%f,%f,%f]\n", x, y, z, w);
	}
	
	// Getters
	Vector4& getVector4()
	{
		Vector4 vijk(x, y, z, w);
		return  vijk;
	}
	float getVector4x()
	{
		return x;
	}
	float getVector4y()
	{
		return y;
	}
	float getVector4z()
	{
		return z;
	}
	float getVector4w()
	{
		return w;
	}

	// Setters
	float setVector4x(float v)
	{
		x = v; return x;
	}
	float setVector4y(float v)
	{
		y = v; return y;
	}
	float setVector4z(float v)
	{
		z = v; return z;
	}
	float setVector4w(float v)
	{
		w = v; return w;
	}



};

