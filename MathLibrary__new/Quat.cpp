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
	printf("[(w= %f),(%f,%f,%f)]\n" , w, x, y, z);
}
void Quaternion::printVector3(std::string note)
{
	 std::cout << note;
	 printf(" [Quaternion::PrintVector3] Vector3 = (%f,%f,%f)\n", vector3Quat.getVector3x(), vector3Quat.getVector3y(), vector3Quat.getVector3z());

}

Quaternion Quaternion::operator+(Quaternion q)
{
	// w1 v1 + w2 v2
	// w1+w2 + vx1+vx2 + yv1+yv2 + zv1+zv2
	
	w = w + q.w;
	x = x + q.x;
	y = y + q.y;
	z = z + q.z;

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

Quaternion Quaternion::operator*(float s)
{
	//Vector3 qs(x, y, z);
	x = x * s;
	y = y * s;
	z = z * s;
	w = w * s;
	Quaternion ijkw(x, y, z, w);
	//ijkw.operator=(ijkw);
	//Quaternion ijkw(w = w * s, x = qs.getVector3x() * s, y = qs.getVector3y() * s, z = qs.getVector3z() * s);
	//ijkw.operator=(ijkw);
	return ijkw;
}

Quaternion Quaternion::operator*(Quaternion q)
{
	/// Data
	float i = x;
	float j = y;
	float k = z;
	float w1 = w;														 // printf("[function Quat operator*]w = %f\n", w1);
	float w2 = q.w;												 // printf("[function Quat operator*]w = %f\n", w2);
	//Vector3 v1 = (vector3Quat.getVector3());							 // v1.print("[function Quat operator* , Vector3::GetVector3()] v1 = ");
	//Vector3 v2(q.x, q.y, q.z, q.w);	     // v2.print("[function Quat operator* , Vector3::GetVector3()] v2 = ");
	Quaternion q1(i,j,k,w);										 // q1.print("[function Quat operator* , v1 Quaternion = ");
	Quaternion q2(q);											 // q2.print("[function Quat operator* , v2 Quaternion = ");

	/// Formula 2
	/*
		 q1 = <a,b,c,d>  && q2 = <e,f,g,h>
		 <a,b,c,d> * <e,f,g,h>
			i,j,k		i,j,k

		ae + af(i) + ag(j) + ah(k)
		be(i) + bf(i^2) + bg(ij) + bh(ik)		// i
		ce(j) + cf(ji) + cg(j^2) + ch(jk)		// j
		de(k) + df(ki) + dh(kj) + dh(k^2)		// k
	
		ijk = -1	
		i^2 = -1	ij = k		ji = -k
		j^2 = -1	jk = i		kj = -i
		k^2 = -1	ki = j		ik = -j

		solve for 
		ii	= -1
		kk	= -1
		jj	= -1

		ji	= -k		ij = k
		jk	= i			kj = -i
		ki	= j			ik = -j
		

		bg(ij)	 -> iijk = -1	=  i^2jk = -1i	=	-jk = -i	-> jk = i
		jk = i	 -> jjk = i		=	j^2k = ji	=	-k = ji		
		// ji = -k	-> ij = k
		-k = jii ->	-ki = j^2	=	-ki = -j	=	ki = j
		// ki = j	-> ik = -j
		kki = j  -> k^2i = kj	=	-i = kj
		//  kj = -i	-> jk = i
		
			i			j			k
		i	-1			k			-j

		j	-k			-1			i	

		k	j			-i			-1


		 ae + af(i) + ag(j) + ah(k)	+
		 be(i) + bf + bg(k) - bh(j)	+
		 ce(j) - cf(k) + cg + ch(i)	+
		 de(k) + df(j) - dg(i) + dh	+

		 // Set i , j , k in column format
		 w ->	ae , bf , cg , dh
		 i ->	af, be , ch , - dg
		 j ->	ag , - bh , ce , df
		 k ->	ah , bg , -cf , de

		 a = w1
		 e = w2

		 ae - bf - cg - dh 
		 af + be + ch - dg ,
		 ag - bh + ce + df ,
		 ah + bg - cf + de

		 <b ,c ,d> =	 <f, g, h> = 
		 (x1,y1,z1)		 (x2,y2,z2)
		  i, j, k		  i, j, k
		 
		 /// final form
		 w1*w2 - x1*x2 - y1*y2 - z1*z2	// w
		 w1*x2 + x1*w2 + y1*z2 - z1*y2	// i
		 w1*y2 - x1*z2 + y1*w2 + z1*x2	// j
		 w1*z2 + x1*y2 - y1*x2 + z1*w2	// k

		 q1*q2 = w1*w2 - v1 . v2 + w1*v2 + w2*v1 + v1 X v2  

	*/

	/// Working July 2024
	w = w1 * w2 - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	x = w1 * q2.x + q1.x * w2 + q1.y * q2.z - q1.z * q2.y;
	y = w1 * q2.y - q1.x * q2.z + q1.y * w2 + q1.z * q2.x;
	z = w1 * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * w2;

	/// Formula 1
	/*
		* w1*w2 - v1 . v2 + w1v2 + w2v1 + v1 X v2
		* v1 = [x1,y1,z1] v2 = [x2,y2,z2]
		* w1*w2 - x1*x2 - y1*y2 - z1*z2		// w
		* w1*x2 + x1*w2 + y1*z2 - z1*y2		// i
		* w1*y2 + y1*w2 + z1*x2 - x1*z20	// j
		* w1*z2 + z1*w2 + x1*y2 - y1*x2		// k 
	*/
	//float i, j, k;
	//w = w1*w2 - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;				// w
	//x = (w1 * q2.x) + (q1.x * w2) + (q1.y * q2.z) - (q1.z * q2.y);		// i	
	//y = (w1 * q2.y) + (q1.y * w2) + (q1.z * q2.x) - (q1.x * q2.z);		// j	
	//z = (w1 * q2.z) + (q1.z * w2) + (q1.x * q2.y) - (q1.y * q2.x);		// k
	/// Test Answer = 13, 15, 13, 7
	Quaternion ijkw(x,y,z,w);
	////ijkw.print("ijkw =");
	return ijkw;

}

Quaternion Quaternion::operator-(Quaternion q)
{
	// [w1 - w2 , x1 - x2 , y1 - y2 , z1 - z2 - w1 - w2]
	x = x - q.x;
	y = y - q.y;
	z = z - q.z;
	w = w - q.w;
	Quaternion ijkw(x,y,z,w);
	return ijkw;
}

Quaternion Quaternion::operator=(Quaternion& q)
{	// Debug
	/*	
		// q.print("q=");
		// Quaternion ijkw(x,y,z,w);		
		//  ijkw.print("ijkw=");
	*/
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
	Quaternion ijkwz(x,y,z,w);
	//ijkwz.print("ijkw=");
	return ijkwz;
}

Quaternion Quaternion::operator/(float s)
{
	
	x = x / s;
	y = y / s;
	z = z / s;
	w = w / s;


	Quaternion div(x,y,z,w);
	return div;
}



Vector3 Quaternion::rotateQuaternion(Vector3 v)
{
	/// Function Requirments !
	/*
		//  Testing Vec3 Rotate(Vec3 vec)
		//  First create a quaternion that represents a rotation of 90 degrees about the z axis
		//  Then rotate the vector [1, 0, 0] by this quaternion
		//  Your result should be [0 , 1, 0]

		cos(theta / 2) + sin(theta / 2) * x , sin(theta / 2) * y , sin(theta / 2) * z 
				w		[		x			,		y			 ,		z			]

											(v) = qvq*
									pure quaternion * vector * conjugate quaternion
	*/

	/* To rotate a Quaternion :
		// Set Incoming Quaternion Q, and turn into a new Vector3 Quaternion -> (w , Vector3)
		// Set Incoming Quaternion to inverse (-w , -v)
		// Result -> Original Quaternion * newly Set Vector3 Quaternion * Original Quaternion inversed

		//Quaternion Q(w = 0, vecQuat);	Q.print("Newley set Vector3 Quaternion = ");
		//Q.inverseQuaternion(Q);
		//Quaternion Qinverse(Q);
		//Qinverse.print("Qinverse = ");

		// Z Rotate
		//	 cos0		-sin0	0
		//	 sin0		cos0	0
		//		0		0		1
	*/		

	float angle = w;
	float i = x;
	float j = y;
	float k = z;
	float W = w;

	float I = x;
	float J = y;
	float K = z;
	float W_ = w;

	v.print("original v vector3");
	Quaternion original_quaternion(I, J, K, W_);
	original_quaternion.print("original_quaternion");

	Quaternion pure_quaternion;
	pure_quaternion.vector3ToQuaterion(v);
	pure_quaternion.print("pure_quaterion");

	Quaternion conjugate_quaternion(i,j,k,W);
	conjugate_quaternion.conjugateQuaternion(conjugate_quaternion);
	conjugate_quaternion.print("conjugate_quaterion");
	
	pure_quaternion.operator*(original_quaternion); // * conjugate_quaterion;
	pure_quaternion.print("result1");
 


	
	/*
	Quaternion Q_start(i, j, k, W);
	Q_start.print("Q start=");

	Quaternion Q(v.getVector3x(), v.getVector3y(), v.getVector3z() , 0.0f);
	Q.print("Q Vector3=");
	Quaternion Q_inverse; 
	Q_inverse.inverseQuaternion(Q);
	Q_inverse.print("Q inversed=");

	Q_start.operator*(Q);			Q_start.print("Q_start * Q");
	Q_start.operator*(Q_inverse);	Q_start.print("Q_start * inverse");
	//Q_start.operator*(Q_inverse);	Q_start.print("Q_start inverse *");

	//Quaternion result Q_start * Q * Q_inverse
	*/

	Vector3 vv;

	return vv;

	// Data
	//float angle = w * RADIANStoDEGREES;			printf("[Quaternion::rotateQuaternion] angle = %f\n", w);
	//float i, j, k;
	//float I,J,K;
	//
	//float X = x;
	//float Y = y;
	//float Z = z;
	//float W = w;
	//
	//i = v.getVector3x();			
	//j = v.getVector3y();			
	//k = v.getVector3z();			
	//Vector3 vecQuatNormal(i, j, k);									vecQuatNormal.print("[Quaternion::rotateQuaternion] vector3 QuatNormal = ");
	//Quaternion vecQuatNormalQuaternion(i, j, k, angle);				vecQuatNormalQuaternion.print("[Quaternion::rotateQuaternion] vecQuatNormalQuaternion = ");
	//float angleC = cos(angle); // * RADIANStoDEGREES;
	//float angleS = sin(angle); // * RADIANStoDEGREES;
	////angleC = angleC * RADIANStoDEGREES;
	//printf("cos angle radians = %f\n", angleC);
	//
	//return vecQuatNormal;

	// Class Notes
	/*
	//printf("sin angle Degrees = %f\n", angleS);
	//vecQuatNormal.normalize(vecQuatNormal);							vecQuatNormal.print("[Quaternion::rotateQuaternion] vector3 QuatNormalized = ");
	//
	//Quaternion quatVector3(i,j,k, 0.0f);							quatVector3.print("[Quaternion::rotateQuaternion] Quaternion quatVector3 = ");
	//quatVector3.inverseQuaternion(quatVector3);						quatVector3.print("[Quaternion::rotateQuaternion] Quaternion quatVector3 inverse = ");
	//
	//
	//
	//float radCos , radSin, fCos , fSin;
	//radCos = cos(angle) * RADIANStoDEGREES;	printf("radCos=%f\n",radCos);
	//radSin = sin(angle) * RADIANStoDEGREES;	printf("radSin=%f\n",radSin);
	//
	//fCos = radCos / 2;												printf("radCos=%f\n", fCos);
	//fSin = radSin / 2;												printf("radSin=%f\n", fSin);
	
	//Vector3 vecQuatNormalScalar; // (i * fSin, j * fSin, k * fSin);		vecQuatNormalScalar.print("vecQuatNormalScalar = ");
	//printf("I=%f\n", i);
	//printf("J=%f\n", j);
	//printf("K=%f\n", k);
	//vecQuatNormalScalar.print("vecQuatNormalScalar = ");

	//vecQuatNormalScalar.print("[Quaternion::Rotation()] vecQuatNormalScalar =");
	*/
}


Quaternion Quaternion::rotateQuaternion(Quaternion q)
{
	/*
		// steps
		// Construct Quaternion rotated about the axis w , which is acting as theta angle
		// Q = (sin(theta/2) , cos(theta/2)(x) , cos(theta/2)(y) , cos(theta/2)(z)
		// 1. convert Quaternion into Vector3
		// 2. Q formula , using Vector3 coords
		// 3. reconstruct Vector3 into Quaternion with new Coords [w,v]

		Data
		vecQuat3.x
		vecQuat3.y
		vecQuat3.z
		theta = w * 3.1415926535 / 180
		ctheta = cos(w/2)
		stheta = sin(w/2)

	*/
	/*Debug
		//printf("Data\n");
		//printf("converted Quaternion to Vector3 =(%f,%f,%f)\n", vecQuat3.x, vecQuat3.y, vecQuat3.z);
		//printf("w coord = %f\n", w);
	*/

	// q = (s , v) = s(costheta / 2) , v(sintheta / 2)
	// nope !
	Quaternion newQuat(vecQuat3.x, vecQuat3.y, vecQuat3.z, w);
	//newQuat.print("newQuat=");

	// conv Deg to rad -> 2(pi)/360 || conv Rad to Deg -> (180/pi)
	float theta = w *  RADIANStoDEGREES;
	//printf("theta iN radians = %f\n", theta);
	float ctheta = cos(theta /2) ;
	//printf("cos(theta)=%f\n", ctheta);
	float stheta = sin(theta /2);
	//printf("sin(theta)=%f\n", stheta);

	Quaternion rotatedQuat(newQuat.x * stheta, newQuat.y * stheta, newQuat.z * ctheta, ctheta);
	rotatedQuat.print("new rotated Quaternion = ");
	return q;
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
	float w_ = W;

	x = i;			
	y = j;			
	z = k;			
	w = w_;		

	// w - xi - yj - zk
	//Quaternion ijk(i,j,k,w_);
	Quaternion ijk(x,y,z,w);
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

	// conjugate / mag squared
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

// set input Vector3 to pure quaternion
Quaternion Quaternion::vector3ToQuaterion(Vector3& v)
{
	x = v.getVector3x();
	y = v.getVector3y();
	z = v.getVector3z();
	w = 0;
	Quaternion ijkw(x,y,z,w);
	return ijkw;
}


Quaternion::~Quaternion()
{
	//printf("Deleting Quaternion Scene :: File Location %s", __FILE__);
	//printf("Im beyond disappointed with my self this Semester....\n");
}

//#undef PI;
//#undef RADIANStoDEGREES;