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
		x = vector4Plane.setVector4x(v.getVector4x());
		y = vector4Plane.setVector4y(v.getVector4y());
		z = vector4Plane.setVector4z(v.getVector4z());
		w = vector4Plane.setVector4w(v.getVector4w());
	}
	plane(float x_, float y_, float z_, float w_)
	{
		x = vector4Plane.setVector4x(x_);
		y = vector4Plane.setVector4y(y_);
		z = vector4Plane.setVector4z(z_);
		w = vector4Plane.setVector4w(w_);
	}



	void operator=(Vector4 p);
	//void operator=(Vector3 p);


};

