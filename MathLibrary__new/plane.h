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
	Vector4 vector4p1;
	Vector4 vector4p2;
	Vector4 vector4p3;
	rayLine raylinePlane;
	float x, y, z, w;
	float p1_x, p1_y, p1_z, p1_w;
	float p2_x, p2_y, p2_z, p2_w;
	float p3_x, p3_y, p3_z, p3_w;

	/// NOTE my back fkn hurts, and i need to walk....come back and change the xyzw to p1, p2 , p3 etc, depending on how many the user adds
	/// each point will go up like an array, maybe I should make an array lol, a vector array *_- wink wink
	void setPlaneCoords(Vector4& v)
	{
		 x = v.getVector4x();
		 y = v.getVector4y();
		 z = v.getVector4z();
		 w = v.getVector4w();
	}
	void setPlaneCoords(Vector4& v1, Vector4& v2)
	{
		x = v1.getVector4x();
		y = v1.getVector4y();
		z = v1.getVector4z();
		w = v1.getVector4w();
	}


public:
	void print()
	{
		vector4Plane.print("plane");
		printf("Plane (x,y,z,w) = (%f,%f,%f,%f)\n", x, y, z, w);	
	}
	void print(const char* n)
	{
		printf("[%s] Plane (x,y,z,w) = (%f,%f,%f,%f)\n", n , x, y, z, w);
		vector4Plane.print("plane");
		
		//printf("Plane p1 (x,y,z,w) = (%f,%f,%f,%f)\n", p1_x, p1_y, p1_z, p1_w);
		//printf("Plane p2 (x,y,z,w) = (%f,%f,%f,%f)\n", p2_x, p2_y, p2_z, p2_w);
		//printf("Plane p3 (x,y,z,w) = (%f,%f,%f,%f)\n", p3_x, p3_y, p3_z, p3_w);
	}

	void printP1()
	{
		printf("Vector4P1 = (%f,%f,%f,%f)\n",
			vector4p1.getVector4x(),
			vector4p1.getVector4y(),
			vector4p1.getVector4z(),
			vector4p1.getVector4w()
		);
	}
	void printP1(const char* n)
	{
		printf("[%s] Vector4P1 = (%f,%f,%f,%f)\n" , n , 
			vector4p1.getVector4x(),
			vector4p1.getVector4y(),
			vector4p1.getVector4z(),
			vector4p1.getVector4w()
		 );
	}

	void printP2()
	{
		printf("Vector4P2 = (%f,%f,%f,%f)\n",
			vector4p2.getVector4x(),
			vector4p2.getVector4y(),
			vector4p2.getVector4z(),
			vector4p2.getVector4w()
		);
	}
	void printP2(const char* n)
	{
		printf("[%s] Vector4P2 = (%f,%f,%f,%f)\n", n,
			vector4p2.getVector4x(),
			vector4p2.getVector4y(),
			vector4p2.getVector4z(),
			vector4p2.getVector4w()
		);
	}

	void printP3()
	{
		printf("Vector4P3 = (%f,%f,%f,%f)\n",
			vector4p3.getVector4x(),
			vector4p3.getVector4y(),
			vector4p3.getVector4z(),
			vector4p3.getVector4w()
		);
	}
	void printP3(const char* n)
	{
		printf("[%s] Vector4P3 = (%f,%f,%f,%f)\n", n,
			vector4p3.getVector4x(),
			vector4p3.getVector4y(),
			vector4p3.getVector4z(),
			vector4p3.getVector4w()
		);
	}
	~plane();
	plane();
	// One point
	plane(Vector4& v)
	{
		vector4Plane.setVector4xyzw(v);
		setPlaneCoords(v);
		//x = vector4Plane.setVector4x(v.getVector4x());
		//y = vector4Plane.setVector4y(v.getVector4y());
		//z = vector4Plane.setVector4z(v.getVector4z());
		//w = vector4Plane.setVector4w(v.getVector4w());
	}
	plane(float x_, float y_, float z_, float w_)
	{
		x = vector4Plane.setVector4x(x_);
		y = vector4Plane.setVector4y(y_);
		z = vector4Plane.setVector4z(z_);
		w = vector4Plane.setVector4w(w_);
	}
	// Two Points
	plane(Vector4& v1, Vector4& v2)
	{
		setPlaneCoords(v1, v2);
		vector4p1.setVector4xyzw(v1);
		vector4p2.setVector4xyzw(v2);
	}

	plane(Vector4& v1, Vector4& v2 , Vector4& v3)
	{
		vector4p1.setVector4xyzw(v1);
		vector4p2.setVector4xyzw(v2);
		vector4p3.setVector4xyzw(v3);
	}



	void operator=(Vector4 p);
	//void operator=(Vector3 p);


};

