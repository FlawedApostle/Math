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
	// vector4
	Vector4 vector4Plane;			// deprecated
	Vector4 vector4p1;
	Vector4 vector4p2;
	Vector4 vector4p3;
	// vector3 
	Vector3 vector3Plane;			// deprecated
	Vector3 vector3p1;
	Vector3 vector3p2;
	Vector3 vector3p3;
	rayLine raylinePlane;
	float x, y, z, w;

	/// NOTE my back fkn hurts, and i need to walk....come back and change the xyzw to p1, p2 , p3 etc, depending on how many the user adds
	/// each point will go up like an array, maybe I should make an array lol, a vector array *_- wink wink
	void setPlaneCoords(Vector4& v)
	{
		vector4p1.setVector4xyzw(v);
		
		 /*
		 x = v.getVector4x();
		 y = v.getVector4y();
		 z = v.getVector4z();
		 w = v.getVector4w();
		 */

	}
	void setPlaneCoords(Vector4& v1, Vector4& v2)
	{
		vector4p1.setVector4xyzw(v1);
		vector4p2.setVector4xyzw(v2);
		/*
		x = v1.getVector4x();
		y = v1.getVector4y();
		z = v1.getVector4z();
		w = v1.getVector4w();
		*/
	}

	void setPlaneCoords(Vector3& v)
	{
		vector3p1.setVector3xyz(v);
	}
	void setPlaneCoords(Vector3& v1, Vector3& v2)
	{
		vector3p1.setVector3xyz(v1);
		vector3p2.setVector3xyz(v2);
	}
	void setPlaneCoords(Vector3& v1, Vector3& v2, Vector3& v3)
	{
		vector3p1.setVector3xyz(v1);
		vector3p2.setVector3xyz(v2);
		vector3p3.setVector3xyz(v3);
	}

public:
	// Printing - yuck.....
	void print()
	{
		//vector4Plane.print("plane v4");		// deprecated
		//vector3Plane.print("plane v3");		// deprecated
		// vector3

				// vector4
		if (vector4p1.getVector4x() == 0 && vector4p1.getVector4y() == 0 && vector4p1.getVector4z() == 0,
			vector4p2.getVector4x() == 0 && vector4p2.getVector4y() == 0 && vector4p2.getVector4z() == 0,
			vector4p3.getVector4x() == 0 && vector4p3.getVector4y() == 0 && vector4p3.getVector4z() == 0
			)
		{
			printf("error , vector4 null\n");
		}
		else
		{
			// vector4
			vector4p1.print("[vec4] p1");
			vector4p2.print("[vec4] p2");
			vector4p3.print("[vec4] p3");
		}
		// vector3
		if (vector3p1.getVector3x() == 0 && vector3p1.getVector3y() == 0 && vector3p1.getVector3z() == 0,
			vector3p2.getVector3x() == 0 && vector3p2.getVector3y() == 0 && vector3p2.getVector3z() == 0,
			vector3p3.getVector3x() == 0 && vector3p3.getVector3y() == 0 && vector3p3.getVector3z() == 0
			)
		{
			printf("error , vector3 null\n");
		}
		else
		{
			vector3p1.print("[vec3] p1");
			vector3p2.print("[vec3] p2");
			vector3p3.print("[vec3] p3");
		}

	}
	void print(const char* n)
	{
		//vector4Plane.print("plane v4");		// deprecated
		//vector3Plane.print("plane v3");		// deprecated
 
		// vector4
		if (vector4p1.getVector4x() == 0 && vector4p1.getVector4y() == 0 && vector4p1.getVector4z() == 0,
			vector4p2.getVector4x() == 0 && vector4p2.getVector4y() == 0 && vector4p2.getVector4z() == 0,
			vector4p3.getVector4x() == 0 && vector4p3.getVector4y() == 0 && vector4p3.getVector4z() == 0
			)
		{
			printf("error , vector4 null\n");
		}
		else
		{
			// vector4
			vector4p1.print(n);
			vector4p2.print(n);
			vector4p3.print(n);
		}
		// vector3
		if (vector3p1.getVector3x() == 0 && vector3p1.getVector3y() == 0 && vector3p1.getVector3z() == 0,
			vector3p2.getVector3x() == 0 && vector3p2.getVector3y() == 0 && vector3p2.getVector3z() == 0,
			vector3p3.getVector3x() == 0 && vector3p3.getVector3y() == 0 && vector3p3.getVector3z() == 0
			)
		{
			printf("error , vector3 null\n");
		}
		else
		{
			// vector3
			vector3p1.print(n);
			vector3p2.print(n);
			vector3p3.print(n);
		}


	}
	// Vec4 Prints
	void printP1v4()
	{
		vector4p1.print("[vec4] p1");
	}
	void printP1v4(const char* n)
	{
		vector4p1.print(n);
	}
	void printP2v4()
	{
		vector4p2.print("[vec4] p2");
	}
	void printP2v4(const char* n)
	{
		vector4p2.print(n);
	}
	void printP3v4()
	{
		vector4p3.print("[vec4] p3");
	}
	void printP3v4(const char* n)
	{
		vector4p3.print(n);
	}
	// Vec3 Prints
	void printP1v3()
	{
		vector3p1.print("[vec3] p1");
	}
	void printP1v3(const char* n)
	{
		vector3p1.print(n);
	}
	void printP2v3()
	{
		vector3p2.print("[vec3] p2");
	}
	void printP2v3(const char* n)
	{
		vector3p2.print(n);
	}
	void printP3v3()
	{
		vector3p3.print("[vec3] p3");
	}
	void printP3v3(const char* n)
	{
		vector3p3.print(n);
	}
	
	
	
	// Constructors
	~plane();
	plane();
	// Vector4 Constructors
	plane(Vector4& v)
	{
		//vector4Plane.setVector4xyzw(v);
		setPlaneCoords(v);
	}
	plane(Vector4& v1, Vector4& v2)
	{
		setPlaneCoords(v1, v2);
		vector4p1.setVector4xyzw(v1);
		vector4p2.setVector4xyzw(v2);
	}

	plane(Vector4& v1, Vector4& v2, Vector4& v3)
	{
		vector4p1.setVector4xyzw(v1);
		vector4p2.setVector4xyzw(v2);
		vector4p3.setVector4xyzw(v3);
	}
	// Vector3 Constructors
	plane(Vector3& v3)
	{
		setPlaneCoords(v3);
	}
	plane(Vector3& v3a , Vector3& v3b)
	{
		setPlaneCoords(v3a, v3b);
	}
	plane(Vector3& v3a, Vector3& v3b, Vector3& v3c)
	{
		setPlaneCoords(v3a, v3b, v3c);
	}
	//plane(float x_, float y_, float z_, float w_)
	//{
	//	x = vector4Plane.setVector4x(x_);
	//	y = vector4Plane.setVector4y(y_);
	//	z = vector4Plane.setVector4z(z_);
	//	w = vector4Plane.setVector4w(w_);

	//	x = vector3Plane.setVector3x(x_);
	//	y = vector3Plane.setVector3y(y_);
	//	z = vector3Plane.setVector3z(z_);
	//	//w = vector3Plane.setVector3w(w_);
	//}



	void operator=(Vector4 p);
	//void operator=(Vector3 p);


};

