// Samuel Fearnley n01047308 Math Lib Summer 2024

#include <iostream>
#include "Vector.h"
#include "sstream"
#include "math.h"
#include "Quat.h"		// new Quaternion class
#include "Vector3.h"	// new Vector3 class
#include "Vector4.h"	// new Vector4 class
#include "rayLine.h"		// new ray class
#include "plane.h"
 
int main()
{
	/// ********************************************************************* START OF Vec3 ********************************************************************************************************************************** //
	printf("START OF Vec3 \n");
	std::cout << std::endl;

	// Vec U , V
	Vec3 U(4, 2, 1);
	Vec3 V(2, 2, 1);

	// This is the assignment Vector Mag coords, I set them to floats, however ints work as well !
	// Vec V - Magnitude of V
	printf("[QUESTION] Magintude of Vector V(2,2,1)\n");  
	V.Mag();
	U.Mag();

	std::cout << std::endl;
	
	// Vec V - Normalize V
	printf("[QUESTION] Normalize of Vector V(2,2,1) \n Note.... Magnitude Will Repeat Line(s) .... Answer is at end of repeated Mag() answer(s) .... This is for debugging purpose... Apologies for inconvenience\n");
	V.Normalize(2, 2, 1);
	
	std::cout << std::endl;

	/// Dot Product
	std::cout << std::endl;
	printf("[QUESTION] Dot Product of V.U)\n");
	Vec3 DotProduct_question;
	DotProduct_question.DotProduct(V, U, 0);
	
	std::cout << std::endl;
	
	printf("[QUESTION] Dot Product of A.B)\n");
	Vec3 A(2, 5, 1);
	Vec3 B(1, 0, -2);
	Vec3 AB_orth_question;
	AB_orth_question.DotProduct(A, B, 0);

	std::cout << std::endl;
	
	printf("[QUESTION] Dot Product of C.D)\n");
	Vec3 C(2, 7, 1);
	Vec3 D(4, 0, 5);
	Vec3 AB_orth_question2;
	AB_orth_question2.DotProduct(C, D, 0);
	std::cout << std::endl;

	printf("[QUESTION] Dot Product of E.F)\n");
	Vec3 E(1, 0, 2);
	Vec3 F(-1, -2, 4);
	Vec3 AB_orth_question3;
	AB_orth_question3.DotProduct(E, F, 0);
	std::cout << std::endl;

	/// Cross Product
	printf("[QUESTION] Cross Product of U*V)\n");
	V.CrossProduct_3(U , V);			// works
	std::cout << std::endl;


/// ********************************************************** Space Nomad Math Lib Summer 2024 ********************************************************************************************************************************** //
///															
//                                                                              	 ^  
//                                                                                  / \
//                                                                                 /   \
//                                                                                /     \
//                                                                               /       \
//                                                                              /         \
//                                                                              |    |    |
//                                                                              |    |    |
//                                                                              |    |    |
//                                                                              |    |    |
//                                                                              \    \    /
//                                                                               \    \  /
//                                                                                \    \/
//                                                                                /\    \
//                                                                               /  \    \
//                                                                              /    \    \
//                                                                              |    |    |
//                                                                              |    |    |
//                                                                              |    |    |
//                                                                              |    |    |
//                                                                              \         /
//                                                                               \       /
//                                                                                \     /
//                                                                                 \   /
//                                                                                  \ /
//                                                                                   v                                                                            
	/// ********************************************************************* START OF Vec4 ********************************************************************************************************************************** //
	printf("START OF Vec4 \n");
	std::cout << std::endl;		// line break --> for easier reading

	Vec4 V4(2, 2, 1 ,1);
	Vec4 U4(4, 2, 1 ,1);


	printf("Vec4 Magnitude V = %f\n" , V4.Magnitude(2, 2, 1));
	//V4.Magnitude(2, 2, 1);
	//printf("Vec4 U4 Magnitude = %f\n" , U4.Magnitude(4, 2, 1));
	std::cout << std::endl;

	printf("Normalize Vec4 V \n");
	V4.Normalize_Vec4(2,2,1);

	std::cout << std::endl;

	printf("Dot Product Vec4 V4.U4 \n");
	Vec4 dot_product_vec4_user;
	Vec3 v_(V4.x , V4.y , V4.z);
	Vec3 u_(U4.x , U4.y , U4.z);
	dot_product_vec4_user.DotProduct(v_, u_, 0);


	std::cout << std::endl;


	printf("[QUESTION] Dot Product of Vec4 Test)\n");
	Vec3 G(4, 4, 4);
	Vec3 H(4, 4, 4);
	Vec3 AB_orth_question4;
	AB_orth_question4.DotProduct_2(G, H, 0);

	std::cout << std::endl;

	printf("[QUESTION] Dot Product of Vec4 Test)\n");
	Vec3 I(1, 0, 2);
	Vec3 J(-1, -2, 4);
	Vec3 AB_orth_question5;
	AB_orth_question5.DotProduct_3(I, J, 0);

	std::cout << std::endl;


	printf("[QUESTION] Cross Product of Vec4 Test)\n");
	Vec3 M(1, 0, 2);
	Vec3 N(-1, -2, 4);
	Vec3 AB_orth_question6;
	AB_orth_question6.CrossProduct_3(M, N);

	std::cout << std::endl;

	printf("[QUESTION] Dot Product of Vec4 Test)\n");
	Vec3 O(-2, 1, 3);
	Vec3 P(5, 2, -1);
	Vec3 AB_orth_question7;
	AB_orth_question7.DotProduct_3(O, P , 0);
	
	std::cout << std::endl;

	/// MagnitudeVec
	Vec3 vecmagTest(3, 4, 12);
	Vec3 vecmag;
	vecmag.MagnitudeVec(vecmagTest);
	printf("VecMag Test\n");
	vecmagTest.print();	// 13

	/// DotProductVec
	Vec3 DPV;
	Vec3 dotVecA(1, 1, 1);
	Vec3 dotVecB(2, 2, 2);
	DPV.DotProductVec(dotVecA, dotVecB , 2);

	/// ********************************************************************* START OF Ray ********************************************************************************************************************************** //
	// Note.... This and the plane, have been giving me issues. Come back to this !!!!!!!
	///Vec3 distancePL;
	///distancePL.DistanceFromPointToLine(Vec3(-3,0,6 ), Vec3(7, 2, 3), Vec3(1, 6, 0));
	
	/// Ray Class
	printf("Ray Class \n");
	Ray ray , rayQ , rayStart;
	Ray rayDirection , rQ;
	
	rayStart.SetStart(-3,0,6);
	//rayStart.printStartPoint();

	rayStart.SetDirection(10, 2, -3);
	//rayStart.printDirection();

	rayStart.SetQ(1, 6, 0);
	//rayStart.printQPoint();

	Vec3 Qpoint = Vec3(1, 6, 0);

	rayStart.rayDistanceVec(rayStart, Qpoint);	

	Ray PlaneEq;

	printf("\nEquation of a Plane\n");
	PlaneEq.equationPlane(Vec3(1, 2, 3), Vec3(1, 1, 1), Vec3(3, 1, 2));
	std::cout << std::endl;


	// Note 1.... This is just a test to check the math was working, prior to implimenting to a function, eventually i'll delete this, for now its just reference!
	/*
		*	float square_root_Add_all = sqrt((pow(2.0f, 2.0f) + (pow(4.0f, 2.0f) + (pow(6.0f, 2.0f)))));
		*	
		*	
		*	float powA = pow(2.0f, 2);
		*	float powB = pow(4.0f, 2);
		*	float powC = pow(6.0f, 2);
		*	
		*	float answerPow = powA + powB + powC;
		*	
		*	float squareAnswerPow = sqrt(answerPow);
		*	
		*	std::cout << powA << std::endl;
		*	std::cout << powB << std::endl;
		*	std::cout << powC << std::endl;
		*	std::cout << answerPow << std::endl;
		*	std::cout << squareAnswerPow << std::endl;
		*	std::cout << square_root_Add_all << std::endl;
	*/

	// Note 2.... This is just a test to check the math was working, prior to implimenting to a function, eventually i'll delete this, for now its just reference!
	/*
		*	int x = 4;
		*	x += 2;
		*	Vec3 v(2, 4, 5);
		*	 vec3 Normalize();
		*	Vec3 N = v.Normalize();
		*	
		*	
		*	Vec3 u(1, 2, 1);
		*	Vec3 w = u + v;
		*	w += u;// w=w+u;
		*	std::cout << w.x << " " << w.y << " " << w.z << std:: endl;
   */
	
   /// ********************************************************************* Quaternion ************************************************************************************************************************************************* //
   // Test Answer  [13, 15, 13, 7]
	Quaternion v1(1, 2, 2, 3);
	Quaternion v1Add(1, 2, 2, 3);
	Quaternion v1Multiplication(1, 2, 2, 3);
	Quaternion v2(2, 1, 2, 5);
	Quaternion v2Copy(2, 1, 2, 5);
	v1.print("[main()] v1 = ");
	v2.print("[main()] v2 = ");
	std::cout << std::endl;
	/// +
	std::cout << "Quaternion +" << std::endl;
	v1Add.operator+(v2);
	v1Add.print("[Quaternion] operator+ test =");
	std::cout << std::endl;
	/// *
	std::cout << "Quaternion *" << std::endl;
	v1Multiplication.operator*(v2);
	v1Multiplication.print("Quaternion operator* test  =");
	std::cout << std::endl;
	/// = 
	std::cout << "Quaternion =" << std::endl;
	Quaternion qEqual(1, 1, 1, 1);
	Quaternion qEqualTwo(9, 8, 45, 25);
	qEqual.operator=(qEqualTwo);
	qEqual.print("Quaternion operator= test =");
	std::cout << std::endl;
	/// - 
	std::cout << "Quaternion -" << std::endl;
	Quaternion qMinus(10,20,30,40);
	Quaternion qMinusTwo(10, 10, 10,10);
	qMinus.operator-(qMinusTwo);
	qMinus.print("Quaternion operator- test =");
	std::cout << std::endl;
	/// ||mag||
	std::cout << "Magnitude" << std::endl;
	Quaternion v3(1, 2, 2, 3);
	float magnitudeQuaterntion_test = v3.magnitudeQuaternion(v3);
	printf("Quaternion Magnitude test = %f\n", magnitudeQuaterntion_test);
	/// normalize
	std::cout << "normalize" << std::endl;
	Quaternion normalizev3_test;
	normalizev3_test.normalizeQuaternion(v3);
	normalizev3_test.print("Quaternion Normalize test =");
	std::cout << std::endl;
	/// conjugate
	std::cout << "Conjugate" << std::endl;
	Quaternion v3Conjugate(0, 2, 3, 0);
	v3Conjugate.conjugateQuaternion(v3Conjugate);
	v3Conjugate.print("Quaternion Conjugate test =");
	std::cout << std::endl;
	std::cout << std::endl;
	/// inverse
	std::cout << "Quaternion inverse" << std::endl;
	// Test Answer [-0.055556,-0.111111,-0.111111] (w = -0.166667)
	Quaternion inverseQuat(1, 2, 2, 3);
	inverseQuat.inverseQuaternion(inverseQuat);
	inverseQuat.print("Quaternion Inverse - test =");
	std::cout << std::endl;
	/// Quaternion multiply --> w is set to last	// 13,15,13,7
	std::cout << "Quaternion multiply" << std::endl;
	Quaternion q1(1, 2, 2, 3);
	Quaternion q2(2, 1, 2, 5);
	q1.operator*(q2);
	q1.print("Quaternion multiply - test");
	std::cout << std::endl;
	/// quaternion Dot	// [7, 13,15,13]
	std::cout << "Quaternion dot" << std::endl;
	float dotQuaternion = q1.dotQuaternion(q2);
	printf("Quaternion dot - test 1 = %f\n", dotQuaternion);
	std::cout << std::endl;

	/// quaternion mag * mag dot product
	std::cout << "Quaternion dot function 2 - test" << std::endl;
	Quaternion dotProduct1(1, 2, 2, 7);
	Quaternion dotProduct2(2, 1, 2, 5);
	float dotTest2 = dotProduct1.dotQuaternion(dotProduct2);
	printf("dotTest2=%f\n", dotTest2);
	std::cout << std::endl;

	/// Multiply Quaternion with Scalar Value
	Quaternion sV(2, 2, 2, 2);
	sV.operator*(2);
	sV.print("Scalar Value * Quaternion=");
	std::cout << std::endl;
	/// Vector3 to quaternion
	/*
	std::cout << "Vector3 to Quaternion" << std::endl;
	Vector3 vector3Rot(1, 0, 0);
	Quaternion vtQ = vtQ.vector3ToQuaterion(vector3Rot);
	vtQ.print("vector3 to Quaternion");
	std::cout << std::endl;
	*/
	/// quaternion Rotate
	std::cout << "Quaternion Rotate" << std::endl;
	// [1,0,0] w = 90
	//Vector3 vector3Rot(0.149, -0.149, 0.149);								// TEST
	//Quaternion quatRot(0.149, -0.149, 0.149, .9659);						// AN = [.9659 , (.2588 , 0 , 0)]
	//Quaternion quatRot(1, 0, 0, 30);										// AN = [.9659 , (.2588 , 0 , 0)]
	//quatRot.rotateQuaternion(quatRot);

	Vector3 vector3Rot(1, 0, 0);
	Quaternion quatRot(0, 0, 1, 90);
	quatRot.rotateQuaternion(vector3Rot);
	
	//quatRot.print("quatRot = ");
	std::cout << std::endl;
	/// quaterion vector3 -print test
	/*
	std::cout << "quaterion vector3" << std::endl;
	Quaternion vector3test(10, 10, 10, 10);
	vector3test.getQuaternionVector3();
	vector3test.printVector3("vector3test");
	std::cout << std::endl;
	*/
	/// quaternion , Vector3 to pure Quaternion
	/*
	std::cout << "vector3 to pure quaterion" << std::endl;
	Vector3 vector3toQuat(2, 2, 2);
	vector3toQuat.print("vector3toQuat");
	Quaternion vector3test;
	vector3test.vector3ToQuaterion(vector3toQuat);
	vector3test.print("vector3test to pure quaternion");
	std::cout << std::endl;
	*/

///************************************************** new - Vector4 *****************************************************//
	/*
	Vector4 Vector4Test(7, 6, 5, 4);	Vector4Test.print("Vector4Test");
	Vector3 Vector3Test(1, 2, 3);		Vector3Test.print("Vector3Test");
	Vector4 Vector3to4(Vector3Test);
	Vector3to4.print("Vector3 into a Vector4 constructor");

	// Vector4  - Add
	printf("Vector4  - Add test\n");
	Vector4Test.operator+(Vector3to4);
	Vector4Test.print("Vector4Test +");
	std::cout << std::endl;

	// Vector4  - minus
	printf("Vector4  - minus test\n");
	Vector4Test.operator-(Vector3to4);
	Vector4Test.print("Vector4Test -");
	std::cout << std::endl;

	// Vector4  - multiply			--> setting new var mul1
	printf("Vector4  - multiply test\n");
	Vector4 mul1(2, 2, 2, 2);
	mul1.operator*(mul1);
	mul1.print("Vector4Test multiply");
	std::cout << std::endl;

	// Vector4  - multiply scalar	--> using mul1 var
	printf("Vector4  - multiply scalar test\n");
	mul1.operator*(1);
	mul1.print("Vector4Test multiply scalar");
	std::cout << std::endl;

	// Vector4  - dot
	printf("Vector4  - Dot test\n");
	float dotV4 =  Vector4Test.dotVector4(Vector4Test, Vector3to4);
	printf("Vector4Test - dot = %f\n", dotV4);
	std::cout << std::endl;

	 // Vector4  - mag
	 printf("Vector4  - mag test\n");
	 float magV4 = Vector4Test.magVector4(Vector4Test);
	 printf("Vector4Test - mag = %f\n", magV4);
	 std::cout << std::endl;

	 // Vector4  - cross
	 printf("Vector4  - cross test\n");
	 Vector4 c1(4, 2, 1, 5);
	 Vector4 c2(2, 2, 1, 5);
	 c1.crossVector4(c1 , c2);
	 c1.print("Vector4Test - cross");
	 std::cout << std::endl;

	 // Vector4  =
	 std::cout << "operator=" << std::endl;
	 Vector4 change(1, 1, 1, 1);
	 change.print("change before change");
	 Vector4 changeto(2, 2, 2, 2);
	 change.operator=(changeto);
	 change.print("change changeto");
	 std::cout << std::endl;

	 */
///************************************************** new Vector3 *****************************************************//
	/*
	 printf("Vector3  - cross test\n");
	 Vector3 cv1(4, 2, 1);
	 Vector3 cv2(2, 2, 1);
	 cv1.crossProduct(cv1, cv2);
	 cv1.print("Vector3 test - cross");
	 std::cout << std::endl;
	 Vector3 vtt(2, 9, 4);
	 Vector3 vt(vtt);
	 vt.print();
	 */
///************************************************** new rayLine class *****************************************************//
	/*
	//Vector3 r1(2, 4, 6);
	//Vector3 r2(4, 8, 10);
	
	//rayLine rayL(r1,r2);
	//rayL.printStart("rayL - Start");
	//rayL.printEnd("rayL - End");
	//rayL.currentPosition(2);
	//rayL.print("currentPosition");
	*/
	///************************************************** new plane class *****************************************************//
	Vector3 pt3(7, 12, 8);
	Vector3 pt2(19, 24, 38);
	Vector3 pt1(2003, 40, 60);
	plane pt(pt1, pt2 , pt3);
	pt.print("pt3");
	//Vector4 pt1(10, 9, 8, 7);
	//Vector4 pt2(7,6,5,4);
	//Vector4 pt3(25,8,23,2);
	//
	//pt.operator=(pt1);
	//pt.print("pt says hello !");
	//
	//plane pV(pt1, pt2);
	//plane pVv(pt1, pt2, pt3);
	//pV.printP1();
	//pV.printP2();
	//pVv.printP3();
	//
	//pVv.print("pVv");
  

	
}

