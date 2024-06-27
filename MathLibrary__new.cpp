// Samuel Fearnley n01047308 Math Lib Summer 2024

#include <iostream>
#include "Vector.h"
#include "sstream"
#include "math.h"
#include "Quat.h"
#include "Vector3.h"
#include "Vector4.h"
 
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


	/// ****************************************************Samuel Fearnley n01047308 Math Lib Summer 2024 ********************************************************************************************************************************** //
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
   /// Test Answer  [13, 15, 13, 7]
	Quaternion v1(1, 2, 2, 3);
	Quaternion v1Add(1, 2, 2, 3);
	Quaternion v1Multiplication(1, 2, 2, 3);
	Quaternion v2(2, 1, 2, 5);
	Quaternion v2Copy(2, 1, 2, 5);
	v1.print("[main()] v1 = ");
	v2.print("[main()] v2 = ");
	// +
	v1Add.operator+(v2);
	v1Add.print("[main()] Addition Quaternion test =\n");
	// *
	v1Multiplication.operator*(v2);
	v1Multiplication.print("Multiply Quaternion test =\n");
	// ||Q||
	std::cout << std::endl;
	Quaternion v3(1, 2, 2, 3);
	float magnitudeQuaterntion_test = v3.magnitudeQuaternion(v3);
	printf("[main()] Mag test v3 = %f\n", magnitudeQuaterntion_test);
	// normalize
	Quaternion normalizev3_test;
	normalizev3_test.normalizeQuaternion(v3);
	normalizev3_test.print("Normalize test v3 =");
	// conjugate
	std::cout << std::endl;
	Quaternion v3Conjugate(1, 2, 2, 3);
	v3Conjugate.conjugateQuaternion(v3Conjugate);
	v3Conjugate.print("[main()] Conjugate =");
	std::cout << std::endl;
	// inverse
	/// Test Answer [-0.055556,-0.111111,-0.111111] (w = -0.166667)
	Quaternion inverseQuat(1, 2, 2, 3);
	inverseQuat.inverseQuaternion(inverseQuat);
	inverseQuat.print("[main()] InverseQuat = \n");
	std::cout << std::endl;
	// Rotate
	Quaternion rotateQuat;
	float rotQuatf = 90;
	Vector3 rotateQuatv3(1, 0, 0);
	rotateQuat.rotateQuaternion(rotateQuatv3, rotQuatf);
	/// multiply
	//Quaternion o1(-3,4,1,2);
	//Quaternion o2(2,3,1,-4);
	//float doto1 = o1.dotQuaternion(o2);
	//printf("o1 Dot o2 = %f\n", doto1);
	//// Multiply Quaternion with Scalar Value
	//Quaternion sV(2, 2, 2, 2);
	//sV.operator*(2);
	//sV.print("Scalar Value * Quaternion=");

	std::cout <<std::endl;
///************************************************** Vector4 *****************************************************//
	//Vector4 Vector4Test(7, 6, 5, 4);
	//Vector3 Vector3Test(1, 2, 3);
	//Vector4 Vector4CTest(Vector3Test);
	//Vector4CTest.print("Vector3 into a Vector4 constructor");

	std::cout << std::endl;
///************************************************** Vector3 *****************************************************//
	Vector3 scalarVecTest(2, 4, 6);
	scalarVecTest.operator*(2);
	scalarVecTest.print("scalarVecTest=");
	

	



	


}

