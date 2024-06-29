#include <iostream>
#include "Quat.h"
#include "cmath"
#include "math.h"

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

Quaternion Quaternion::operator*(float scalar)
{
	Vector3 qs(x, y, z);
	Quaternion ijkw(w = w * scalar, x = qs.getVector3x() * scalar, y = qs.getVector3y() * scalar, z = qs.getVector3z() * scalar);
	ijkw.operator=(ijkw);
	return ijkw;
}

Quaternion Quaternion::operator*(Quaternion otherQuat)
{
	/// Data
	float i = x, j = y, k = z;
	float w1 = w;														 // printf("[function Quat operator*]w = %f\n", w1);
	float w2 = otherQuat.w;												 // printf("[function Quat operator*]w = %f\n", w2);
	Vector3 v1 = (vector3Quat.getVector3());							 // v1.print("[function Quat operator* , Vector3::GetVector3()] v1 = ");
	Vector3 v2(otherQuat.x, otherQuat.y, otherQuat.z, otherQuat.w);	     // v2.print("[function Quat operator* , Vector3::GetVector3()] v2 = ");
	Quaternion q1(i,j,k,w);										 // q1.print("[function Quat operator* , v1 Quaternion = ");
	Quaternion q2(otherQuat);											 // q2.print("[function Quat operator* , v2 Quaternion = ");

	/// Formula
	/*
		* w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
		* v1 = [x1,y1,z1] v2 = [x2,y2,z2]
		* w1*w2 - x1*x2 - y1*y2 - z1*z2		// w
		* w1*x2 + x1*w2 + y1*z2 - z1*y2		// i
		* w1*y2 + y1*w2 + z1*x2 - x1*z20	// j
		* w1*z2 + z1*w2 + x1*y2 - y1*x2		// k 
	*/
	//float i, j, k;
	w = w1*w2 - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;				// w
	x = (w1 * q2.x) + (q1.x * w2) + (q1.y * q2.z) - (q1.z * q2.y);		// i	
	y = (w1 * q2.y) + (q1.y * w2) + (q1.z * q2.x) - (q1.x * q2.z);		// j	
	z = (w1 * q2.z) + (q1.z * w2) + (q1.x * q2.y) - (q1.y * q2.x);		// k
	/// Test Answer = 13, 15, 13, 7
	Quaternion ijkw(x,y,z,w);
	////ijkw.print("ijkw =");
	return ijkw;

}

Quaternion Quaternion::operator-(Quaternion Quat1)
{
	// [w1 - w2 , x1 - x2 , y1 - y2 , z1 - z2 - w1 - w2]
	Quaternion ijkw(x,y,z,w);
	return ijkw;
}

Quaternion Quaternion::operator=(Quaternion& q)
{
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;


	Quaternion ijkw(x,y,z,w);
	return ijkw;
}



Vector3 Quaternion::rotateQuaternion(Vector3 q, float theta)
{
	/// Function Requirments !
	/*
		//  Testing Vec3 Rotate(Vec3 vec)
		//  First create a quaternion that represents a rotation of 90 degrees about the z axis
		//  Then rotate the vector [1, 0, 0] by this quaternion
		//  Your result should be [0 , 1, 0]
	*/

	/* To rotate a Quaternion :
		// Set Incoming Quaternion Q, and turn into a new Vector3 Quaternion -> (w , Vector3)
		// Set Incoming Quaternion to inverse (-w , -v)
		// Result -> Original Quaternion * newly Set Vector3 Quaternion * Original Quaternion inversed
	*/		

	// Data
	float angle = theta;			printf("theta = %f\n", angle);
	float i, j, k;
	i = q.getVector3x();
	j = q.getVector3y();
	k = q.getVector3z();
	Vector3 vecQuat(i, j, k);		vecQuat.print("vector3 Quat = ");

	Quaternion Q(w = 0, vecQuat);	Q.print("Newley set Vector3 Quaternion = ");
	Q.inverseQuaternion(Q);
	Quaternion Qinverse(Q);
	Qinverse.print("Qinverse = ");




	
	/// Data
	//float I, J, K;
	//I = axis.getVector3x();
	//J = axis.getVector3y();
	//K = axis.getVector3z();
	//Vector3 Normal(I, J, K);

	//float rotationW;
	//float r , o , t;
	//float rotTheta , rotCos , rotSin;
	//float Rot = rot;
	//r = 2;
	//o = Rot;
	//t = Rot / r;
	//float ROT = t;
	//printf("Rotation 1/2 = %f\n", ROT);
	//
	//// convert from radians to degrees ! 
	//// theta * 3.141592 / 180 = radians
	//// cos(radians) = correct answer 
	//float rot_ = ROT * RADIANStoDEGREES;
	//printf("rot to radians = \%f\n", rot_);
	///// Answer 0.86	
	//rotCos = cos(rot_);	
	//rotSin = sin(rot_);	
	//printf("Rotation cos Theta = %f\n", rotCos);
	//printf("Rotation sin Theta = %f\n", rotSin);


	//Normal.print("[Quaternion::rotateQuaternion()] , Normal =");
	//Normal.normalize(Normal);
	//Normal.print("[Vector3::normalize()] , Normal normalized =");
	//
	//float i, j, k;
	////w = rotationW;
	//
	///// cosVal * rotationAxis * sinVal == rotCos * Normal * rotSin
	//// rotCos = w , Normal * rotSin (scalar multiplication of Vec3)
	//Normal.operator*(rotSin);
	//Normal.print("Normal Vector3 * Scalar Value rotSin=");
	//Vector3 finalaxisOfRotation(Normal.getVector3x(), Normal.getVector3y(), Normal.getVector3z());
	//finalaxisOfRotation.print("Final Axis Rotation Vector3 = ");
	//
	//Quaternion ijkw;
	Vector3 ijkz;
	//ijkw.x = ijkz.setVector3x(finalaxisOfRotation.getVector3x());
	//ijkw.y = ijkz.setVector3y(finalaxisOfRotation.getVector3y());
	//ijkw.z = ijkz.setVector3z(finalaxisOfRotation.getVector3z());
	//ijkw.w = rotCos;
	//
	//ijkz.setVector3x(ijkw.x);
	//ijkz.setVector3y(ijkw.y);
	//ijkz.setVector3z(ijkw.z);
	//ijkz.setVector3w(ijkw.w);


	//ijkw.print("[Quaternion::Rotation()] , ijkw =");
	ijkz.print("[Quaternion::Rotation()] , ijkz =");
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

float Quaternion::dotQuaternion(Quaternion xyzw)
{
	// w1*w2 + x1*x2 + y1*y2 + z1*z2
	float i, j, k, W;

	/*
		 //	printf("xyzw = (%f,%f,%f,%f)\n", x, y, z,w);
		 //	printf("xyzw = (%f,%f,%f,%f)\n", xyzw.x, xyzw.y, xyzw.z, xyzw.w);
		 //		x , y , z , w	xyzw.x
		 //						xyzw.y
		 //						xyzw.z
		 //						xyzw.w
	*/
	i = x * xyzw.x;
	j = y * xyzw.y;
	k = z * xyzw.z;
	W = w * xyzw.w;

	x = i;
	y = j;
	z = k;
	w = W;

	float dotQuat = i+j+k+W;

	return dotQuat;
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

//#undef PI;
//#undef RADIANStoDEGREES;