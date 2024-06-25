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
}
void Quaternion::printVector3(std::string note)
{
	 std::cout << note;
	 printf(" Vector3 = (%f,%f,%f) (w=%f)\n", vector3Quat.getVector3x(), vector3Quat.getVector3y(), vector3Quat.getVector3z() , vector3Quat.getVector3w());

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

	/// Adding the xyz components of Vector3 class, created in Quat constructor
	//vector3Quat.setVector3x(x);
	//vector3Quat.setVector3y(y);
	//vector3Quat.setVector3z(z);
	//vector3Quat.setVector3w(w);

	Quaternion ijkz(x, y, z , w);
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
	// aw*bw a . b + aw*b + bw*a + a X b
	
	// Data
	float w1 = w;														printf("[function Quat operator*]w = %f\n", w1);
	float w2 = otherQuat.w;												printf("[function Quat operator*]w = %f\n", w2);
	Vector3 v1 = (vector3Quat.getVector3());							v1.print("[function Quat operator* , Vector3::GetVector3()] v1 = ");
	Vector3 v2(otherQuat.x, otherQuat.y, otherQuat.z, otherQuat.w);	    v2.print("[function Quat operator* , Vector3::GetVector3()] v2 = ");
	Quaternion q1(x , y , z , w);										q1.print("[function Quat operator* , v1 Quaternion = ");
	Quaternion q2(otherQuat);											q2.print("[function Quat operator* , v2 Quaternion = ");


	// w1*w2
	float W = w1 * w2;													printf("[function Quat operator*]w1*w2 = %f\n", W);
	// v1 . v2															
	float V = vector3Quat.DotProduct(v1 , v2);							printf("[function Quat operator*] v1 . v2 = %f\n", V);
	// v1 X v2
	Vector3 VC = vector3Quat.crossProduct(v1, v2);						VC.print("[function Quat operator*] v1 X v2 =");
	// w1v2 + w2v1
	q1.operator+(q2);													q1.print("[function Quat operator*] q1 = q1 + q2 =");
	Quaternion Q = q1;													Q.print("[function Quat operator*]  Q  = q1 + q2 =");


	// w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
	// w1 * w2 - v1.x * v2.x - v1.y * v2.y - v1.z * v2.z // 1
	// w1 * v2.x + v1.x * w2 + v1.y * v2.z - v1.z * v2.y // i
	// w1 * v2.y - v1.x * v2.z + v1.y * w2 + v1.z * v2.x // j
	// w1 * v2.z + v1.x * v2.y - v1.y * v2.x + v1.z * w2 // k

	
	// a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,  // 1
	// a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,  // i
	// a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,  // j
	// a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w   // k

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