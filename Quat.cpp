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
	
	w = w + Quat1.w;
	x = x + Quat1.x;
	y = y + Quat1.y;
	z = z + Quat1.z;

	float i, j, k, W;
	W = w;
	i = x;
	j = y;
	k = z;

	/// Adding the xyz components of Vector3 class, created in Quat constructor
	//vector3Quat.setVector3x(x);
	//vector3Quat.setVector3y(y);
	//vector3Quat.setVector3z(z);
	//vector3Quat.setVector3w(w);

	Quaternion ijkz(x,y,z,w);
	return ijkz;
	//);
}

Quaternion Quaternion::operator*(Quaternion otherQuat)
{
	/// Data
	float w1 = w;														 // printf("[function Quat operator*]w = %f\n", w1);
	float w2 = otherQuat.w;												 // printf("[function Quat operator*]w = %f\n", w2);
	Vector3 v1 = (vector3Quat.getVector3());							 // v1.print("[function Quat operator* , Vector3::GetVector3()] v1 = ");
	Vector3 v2(otherQuat.x, otherQuat.y, otherQuat.z, otherQuat.w);	     // v2.print("[function Quat operator* , Vector3::GetVector3()] v2 = ");
	Quaternion q1(x , y , z , w);										 // q1.print("[function Quat operator* , v1 Quaternion = ");
	Quaternion q2(otherQuat);											 // q2.print("[function Quat operator* , v2 Quaternion = ");

	/// Formula
	/*
		* w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
		* v1 = [x1,y1,z1] v2 = [x2,y2,z2]
		* w1*w2 - x1*x2 - y1*y2 - z1*z2		// 1
		* w1*x2 + x1*w2 + y1*z2 - z1y2		// i
		* w1*y2 - x1*z2 + y1*w2 + z1*x2		// j
		* w1*z2 + x1*2y - y1*x2 + z1*w2		// k 
	*/
	float i, j, k;
	w = w1*w2 - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;				// T
	i = (w1 * q2.x) + (q1.x * w2) + (q1.y * q2.z) - (q1.z * q2.y);		// T		
	j = (w1 * q2.y) + (q1.y * w2) + (q1.z * q2.x) - (q1.x * q2.z);		// T
	k = (w1 * q2.z) + (q1.z * w2) + (q1.x * q2.y) - (q1.y * q2.x);

	x = i;
	y = j;
	z = k;
	/// Test Answer = 13, 15, 13, 7
	Quaternion ijkw(x,y,z,w);
	//ijkw.print("ijkw =");
	return ijkw;
	
	/// w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
	/*
			* float w1 = w;														printf("w = %f\n", w1);
			* float w2 = otherQuat.w;											printf("w = %f\n", w2);
			* Vec3 v1 = Vec3(vecQuat3);											v1.print("v1 =");
			* Vec3 v2 = Vec3(otherQuat.x, otherQuat.y, otherQuat.z);			v2.print("v2 =");
			* Vec3 otherQuatV = Vec3(otherQuat.x, otherQuat.y, otherQuat.z);	otherQuatV.print("otherQV =");
			* 	// w1*w2				-
			* float W = w1 * w2;												printf("W = %f\n", W);
			* 	// v1. v2				+
			* float dotV = vecQuat3.DotProd(v1 , v2);							printf("v1 . v2 = %f\n", dotV);
			* 	// w1v2 + w2v1			+
			* 	// w1+w2 + x1+x2 + y1+y2 + z1 + z2
			* float WV = w1 + w2 + v1.x + v2.x + v1.y + v2.y + v1.z + v2.z;	printf("w1v2 + w2v1 = %f\n", WV);
			* 	// v1 X v2
			* v1.CrossProduct_3(v1, v2);
	*/
	/*
	* //w1*w2
	* float W = w1 * w2;													printf("[function Quat operator*]w1*w2 = %f\n", W);
	* //v1 . v2
	* float V = vector3Quat.DotProduct(v1 , v2);							printf("[function Quat operator*] v1 . v2 = %f\n", V);
	* //v1 X v2
	* Vector3 VC = vector3Quat.crossProduct(v1, v2);						VC.print("[function Quat operator*] v1 X v2 =");
	* //w1v2 + w2v1
	* q1.operator+(q2);														q1.print("[function Quat operator*] q1 = q1 + q2 =");
	* Quaternion Q = q1;													Q.print("[function Quat operator*]  Q  = q1 + q2 =");
*/

}

Quaternion Quaternion::rotateQuaternion(Vector3 xyz, float rot)
{
	// To rotate a Quaternion:
	// Set w = 0
	// normalize the Now Vector3 (formly a quaterntion vector prior to w being set to 0)
	// cosTheta + vNorm(sinTheta)	('cosTheta & sinTheta are fractions over 2 NOT division in this case, rather a representation of a fraction -> theta / 2')
	// Note.. half the rotation float value
	//							cos(rotValue / 1/2) + sin(rotValue / 1/2) * [i,j,k]
	
	/// Data
	Vector3 Normal(xyz.getVector3x(), xyz.getVector3y(), xyz.getVector3z());
	Normal.printW("[Quaternion::rotateQuaternion()] , Normal =");
	printf("Rotation= %f\n", rot);
	Normal.normalize(Normal);
	Normal.print("[Vector3::normalize()] , Normal normalized =");
	
	

	Quaternion ijkz;
	return ijkz;
}

Quaternion Quaternion::normalizeQuaternion(Quaternion xyzw)
{
	float W = pow(xyzw.w, 2);
	float i = pow(xyzw.x, 2);
	float j = pow(xyzw.y, 2);
	float k = pow(xyzw.z, 2);

	x = i;
	y = j;
	z = k;
	w = W;
	
	float ijkz =  i+j+k+W;
	float ikjw = sqrt(ijkz);

	w = xyzw.w / ikjw;
	x = xyzw.x / ikjw;
	y = xyzw.y / ikjw;
	z = xyzw.z / ikjw;

	//  Test Answer (0.235702, 0.471405, 0.471405, 0.707107)
	Quaternion ikjww(x ,y ,z ,w);
	return ikjww;
}

Quaternion Quaternion::conjugateQuaternion(Quaternion xyzw)
{
	/*
		* Research proposed this is the ideal way of setting an obj to a neg value
		* Concencus is it works, but isn't optimal.
		* Setting each incoming vector indices to a temporary float value on the stack
		* creating a new stack object, then equaling the temporary float indices to a negative value
		* conjugate formula					w - xi - yj - zk
	
	*/
	float I = xyzw.x;
	float i = -I;	
	
	float J = xyzw.y;
	float j = -J;	

	float K = xyzw.z;
	float k = -K;	

	float W = xyzw.w;
	float w_ = -W;

	x = i;			
	y = j;			
	z = k;			
	w = w_;		

	// w - xi - yj - zk
	Quaternion ijk(i,j,k,w_);
	return ijk;
}

Quaternion Quaternion::inverseQuaternion(Quaternion xyz)
{
	// inverse is equal to: 
	// the conjugate divided by the Mag squared
	float I, J, K, W;
	Quaternion magnitude(xyz.x, xyz.y, xyz.z, xyz.w);
	float mag = magnitude.magnitudeQuaternion(magnitude);							// printf("[Quaternion::inverseQuaternion()] , Magnitude= %f\n", mag);


	Quaternion conjugate(xyz.x, xyz.y, xyz.z, xyz.w);								// conjugate.print("[Quaternion::inverseQuaternion()] , Conjugate=");
	conjugate.conjugateQuaternion(conjugate);


	I = conjugate.x / pow(mag,2);													// printf("I=%f\n",I);
	J = conjugate.y / pow(mag,2);													// printf("J=%f\n",J);
	K = conjugate.z / pow(mag,2);													// printf("K=%f\n",K);
	W = conjugate.w / pow(mag,2);													// printf("W=%f\n",W);

	float i, j, k;
	i = I;	
	j = J;	
	k = K;	
	w = W;

	x = i;
	y = j;
	z = k;

	Quaternion ijk(i, j, k,w);
	return ijk;
}

float Quaternion::magnitudeQuaternion(Quaternion xyzw)
{
	float W = pow(xyzw.w, 2);
	float i = pow(xyzw.x, 2);
	float j = pow(xyzw.y, 2);
	float k = pow(xyzw.z, 2);

	//x = i;
	//y = j;
	//z = k;
	//w = W;

	float ijkz = i + j + k + W;
	float ijkMag = sqrt(ijkz);
	return ijkMag;
}


Quaternion::~Quaternion()
{
	//printf("Deleting Quaternion Scene :: File Location %s", __FILE__);
	//printf("Im beyond disappointed with my self this Semester....\n");
}