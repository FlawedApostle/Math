#pragma once
#include "Vector4.h"
#include "Vector3.h"
class rayLine;
class Vector4;
class Vector3;

class plane :  public rayLine
{

protected:
	const char* hello;
	Vector4 vector4Plane;
	rayLine raylinePlane;
	float x, y, z, w;
public:
	void print();
	void print(const char* n);
	~plane();
	plane();
	plane(Vector4& v)
	{
		vector4Plane.setVector4xyzw(v);
	}



	void operator=(Vector4 p);
	//void operator=(Vector3 p);


};

