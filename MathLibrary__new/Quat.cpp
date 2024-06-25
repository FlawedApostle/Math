#include <iostream>
#include "Quat.h"

void Quaternion::print()
{
	printf("(%f,%f,%f,%f)\n", x, y, z, w);

}
void Quaternion::print(std::string note)
{
	 std::cout << note;
	printf("(w = %f) , [%f,%f,%f]\n" , w, x, y, z);
	printf("Vector3 = (%f,%f,%f)\n", vector3Quat.getVector3x(), vector3Quat.getVector3y(), vector3Quat.getVector3z());
}

Quaternion Quaternion::operator+(Quaternion Quat1)
{
	// w1 v1 + w2 v2
	// w1+w2 + vx1+vx2 + yv1+yv2 + zv1+zv2
	//return Quaternion
	//(
	w = w + Quat1.w;
	x = x + Quat1.x;
	y = y + Quat1.y;
	z = z + Quat1.z;
	Quaternion ijkz(w, x, y, z);
	return ijkz;
	//);
}

Quaternion Quaternion::operator*(Quaternion otherQuat)
{
	/// w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
	//float w1 = w;														printf("w = %f\n", w1);
	//float w2 = otherQuat.w;											printf("w = %f\n", w2);
	//Vec3 v1 = Vec3(vecQuat3);											v1.print("v1 =");
	//Vec3 v2 = Vec3(otherQuat.x, otherQuat.y, otherQuat.z);			v2.print("v2 =");
	//Vec3 otherQuatV = Vec3(otherQuat.x, otherQuat.y, otherQuat.z);	otherQuatV.print("otherQV =");
	//	// w1*w2				-
	//float W = w1 * w2;												printf("W = %f\n", W);
	//	// v1. v2				+
	//float dotV = vecQuat3.DotProd(v1 , v2);							printf("v1 . v2 = %f\n", dotV);				
	//	// w1v2 + w2v1			+
	//	// w1+w2 + x1+x2 + y1+y2 + z1 + z2
	//float WV = w1 + w2 + v1.x + v2.x + v1.y + v2.y + v1.z + v2.z;	printf("w1v2 + w2v1 = %f\n", WV);
	//	// v1 X v2		
	//v1.CrossProduct_3(v1, v2);				
	
	/// w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
	// -v1 . v2 + v1 X v2
	float w1 = w;														printf("w = %f\n", w1);
	float w2 = otherQuat.w;												printf("w = %f\n", w2);
	Vector3 v1 = (vector3Quat.getVector3());							v1.print("Vector3 getVector3 = ");


	Quaternion ijkz;
	return ijkz;
}

Quaternion Quaternion::rotateQuaternion(Vec3 xyz, float w)
{


	Quaternion ijkz;
	return ijkz;
}


Quaternion::~Quaternion()
{
	//printf("Deleting Quaternion Scene :: File Location %s", __FILE__);
}