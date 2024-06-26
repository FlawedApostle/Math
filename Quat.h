#pragma once
#include "math.h"
#include "Vector.h"
#include "Vector3.h"
class Vec3;
class Vec4;
class Vector3;

class Quaternion
{
private:
protected:
	Vec4 vecQuat4;
	Vec3 vecQuat3;
	Vector3 vector3Quat;
	Vector3 v3Q;
	float rotQuat3;
	float x;
	float y;
	float z;
	float w;

	// set variables
	void const setQuaternion(float x_, float y_, float z_, float w_)
	{
		x = x_ = 0;
		y = y_ = 0;
		z = z_ = 0;
		w = w_ = 1;
	}

	void const setQuaternionVec4(float x_, float y_, float z_, float w_)
	{

		vecQuat4.x = x_;
		vecQuat4.y = y_;
		vecQuat4.z = z_;
		vecQuat4.w = w_;		
	}

	void const setQuaternionVec3 (float x_, float y_, float z_, float w_)
	{
		vecQuat3.x = x_;
		vecQuat3.y = y_;
		vecQuat3.z = z_;
		w = w_;
	}

	// Set Vector3 class xyzw
	void setQuatVector3(float x_, float y_, float z_, float w_)
	{
		vector3Quat.setVector3x(x);
		vector3Quat.setVector3y(y);
		vector3Quat.setVector3z(z);
		vector3Quat.setVector3w(w);	
	}

public:
	//Quaternion(const Quaternion&) {};
	Quaternion()
	{
		setQuaternion(x, y, z, w);
	}
	Quaternion(float x_, float y_, float z_, float w_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = w_;
		setQuaternionVec3(x_, y_, z_, w_);
		setQuaternionVec4(x_, y_, z_, w_);
		setQuatVector3(x_, y_, z_, w_);
	}
	~Quaternion();
	void print();
	void print(std::string note);
	void printVector3(std::string note);

	// overload the * operator to multiply two quaternions
	Quaternion operator + (Quaternion Quat1);
	Quaternion operator * (Quaternion Quat1);

	//Quaternion rotateQuaternion(Vec3 xyz, float w);
	Quaternion rotateQuaternion(Vector3 xyz, float w);
	Quaternion normalizeQuaternion(Quaternion xyzw);
	Quaternion conjugateQuaternion(Quaternion xyzw);
	Quaternion inverseQuaternion(Quaternion xyzw);
	float magnitudeQuaternion(Quaternion xyzw);



	/// Getters
	Quaternion getQuaternion()
	{
		Quaternion Quaternion(x, y, z, w);
		return Quaternion;
	}
	Vec4 getQuaternionVec4()
	{
		return vecQuat4;
	}
	Vec3 getQuaternionVec3()
	{
		//vecQuat3 = Vec3(vecQuat3.x, vecQuat3.y, vecQuat3.z);
		return vecQuat3;
	}
	Vector3 getQuaternionVector3()
	{
		return vector3Quat.getVector3();
		/*std::cout << vector3Quat.getVector3();*/
	}
};