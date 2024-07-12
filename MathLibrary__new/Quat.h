#pragma once
#include "math.h"
#include "Vector.h"
#include "Vector3.h"
//#define PI 3.145926535;
//#define RADIANStoDEGREES 3.145926535 / 180;
/*
	So w is set to last in my Quaternion constructors. If I'm honest I'm tired of the whole
	'Have to write it this way' ordeal. Lets be real, its imaginary numbers anyway ? so I mean 
	whats the difference. The w is probably the only real number, but it gets treated as an imaginary
	number sometimes. Its all relative ! so here..... 
				I put the SCALAR VALUE w as the final output, not the first !

										q = [w , v]
									    ...Mine is...
										q = [v , w]
*/
class Vec3;
class Vec4;
class Vector3;
struct formula;

class Quaternion
{
private:
protected:
	Vec4 vecQuat4;				// old vec4
	Vec3 vecQuat3;				// old vec3
	Vector3 vector3Quat;		// new vector3 class
	
	float x;
	float y;
	float z;
	float w;
	
	// Struct the formulas
	struct Formula		
	{
		float pi = 3.141592653589793238463;
		float DEGREEtoRADIAN = pi / 180;
		float RADIANtoDEGREE = 180 / pi;
		float ZERO = 0.0f;
		float CLOSE_TO_ZERO = 0.01f;
		float angle90pi = pi / 2;
	};
	Formula formula;

	void const setDefaultQuaternion()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 1;
	}
	// default set quaternion to 0 , I made the mistake of putting w last....
	void const setQuaternion(float x_, float y_, float z_, float w_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}
	// set with Vector3
	void const setQuaternion(float w_ , Vector3& v)
	{
		x = v.getVector3x();
		y = v.getVector3y();
		z = v.getVector3z();
		w = w_;
	}

	void const setQuaternionVec4(float x_, float y_, float z_, float w_)
	{
		vecQuat4.x = x_;
		vecQuat4.y = y_;
		vecQuat4.z = z_;
		vecQuat4.w = w_;		
	}
	// old vec3 class
	void const setQuaternionVec3 (float x_, float y_, float z_, float w_)
	{
		vecQuat3.x = x_;
		vecQuat3.y = y_;
		vecQuat3.z = z_;
		w = w_;
	}

	// Set new Vector3 class xyzw
	void setQuaternionVector3(float x_, float y_, float z_)
	{
		vector3Quat.setVector3x(x);
		vector3Quat.setVector3y(y);
		vector3Quat.setVector3z(z);
	}

public:
	Quaternion()
	{
		setQuaternion(0,0,0,1);
	}
 
	Quaternion(float x_, float y_, float z_, float w_)
	{
		setQuaternion(x_, y_, z_, w_);
		setQuaternionVector3(x_, y_, z_);						// new Vector3

		//setQuaternionVec3(x_, y_, z_, w_);
		//setQuaternionVec4(x_, y_, z_, w_);
	}
	Quaternion(const Quaternion& q)
	{
		setQuaternion(q.x, q.y, q.z, q.w);
		setQuaternionVector3(q.x, q.y, q.z);					// new Vector3
	}
	Quaternion(Vector3& v)
	{
		 v.setVector3x(x);
		 v.setVector3y(y);
		 v.setVector3z(z);
		 w = 0;
	}
	Quaternion(float W , Vector3& v) 
	{
		x = v.getVector3x();
		y = v.getVector3y();
		z = v.getVector3z();
		w = W;
	}
	
	~Quaternion();
	
	void print();
	void print(std::string note);
	void printVector3(std::string note);

	Quaternion operator + (Quaternion q);
	// scalar multiplication
	Quaternion operator*(float s);
	Quaternion operator * (const Quaternion q);
	//Quaternion operator*(const Quaternion& q) const;
	/// Multiply Quaternion by Vector3 || Vector4
	//Quaternion operator * (Vector3& v);
	Quaternion operator - (Quaternion q);
	Quaternion operator=(Quaternion& q);
	// scalar divide
	Quaternion operator/(float s);
	// squared function ?
	

	// working July,2024
	Quaternion rotateQuaternion(Quaternion q);
	Vector3 rotateQuaternion(Vector3 v);

	Quaternion normalizeQuaternion(Quaternion xyzw);
	Quaternion conjugateQuaternion(Quaternion xyzw);
	Quaternion inverseQuaternion(Quaternion xyzw);
	float dotQuaternion(Quaternion xyzw);
	float dotQuaternion(float dotv , float maga , float magb);
	float magnitudeQuaternion(Quaternion xyzw);

	// Vector3 to pure quaternion
	Quaternion vector3ToQuaterion(Vector3& v);

	/// Getters
	Quaternion getQuaternion()
	{
		Quaternion Quaternion(x, y, z, w);
		return Quaternion;
	}
	// old Vec4 
	Vec4 getQuaternionVec4()
	{
		return vecQuat4;
	}
	// old Vec3 
	Vec3 getQuaternionVec3()
	{
		//vecQuat3 = Vec3(vecQuat3.x, vecQuat3.y, vecQuat3.z);
		return vecQuat3;
	}
	// new Vector3
	Vector3 getQuaternionVector3()
	{
		return vector3Quat.getVector3();
	}
};
