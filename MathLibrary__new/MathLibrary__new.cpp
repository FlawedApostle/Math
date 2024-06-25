// Samuel Fearnley n01047308 Math Lib Summer 2024

#include <iostream>
#include "Vector.h"
#include "sstream"
#include "math.h"
#include "Quat.h"
#include "Vector3.h"
 
int main()
{
	// Note ..... Testing Code
	/*
	//Vec3 vec1(1, 1, 1);
	//Vec3 vec2(2, 2, 2);
	//Vec3 vec3(4, 4, 4);
	//vec1.set(1.0f, 1.0f, 1.0f);
	//vec2.set(2.0f, 2.0f, 2.0f);
	//Vec3 vecanswerplus = vec1 + vec2;
	//Vec3 vecanswerplus = vec1 += vec2;
	//std::cout << "vec1 + vec2 = ";
	//std::cout << vecanswerplus.x << " , " << vecanswerplus.y << " , " << vecanswerplus.z << std::endl;
	//Vec3 vecanswermins = vec3 - vec2;
	//Vec3 vecanswermins = vec3 -= vec2;
	//std::cout << "vec3 - vec2 = ";
	//std::cout << vecanswermins.x << " , " << vecanswermins.y << " , " << vecanswermins.z << std::endl;
	//Vec3 vecanswerminsmultiplication = vec2 *= vec2;
	//Vec3 vecanswerminsmultiplication = vec2 * vec2;
	//std::cout << "vec2 * vec2 = ";
	//std::cout << vecanswerminsmultiplication.x << " , " << vecanswerminsmultiplication.y << " , " << vecanswerminsmultiplication.z << std::endl;
	// sin test
	//std::cout << sin(45) << std::endl;
	*/

	/// Questions
	/// Class Work Part 1
	/// Magnitude of V is : 3
	/// Normalized V is : (0.667, 0.667, 0.334)
	/// Dot product V.U is : 13
	/// Cross product UxV is : (0, -2, 4)

	/*
	// vec* operator test
	//Vec3 c(2,2,2);
	//Vec3 z(10,10,10);
	//c.operator*(z);
	*/

	/// ********************************************************************* START OF Vec3 ********************************************************************************************************************************** //
	printf("START OF Vec3 \n");
	std::cout << std::endl;		// line break --> for easier reading

	// Vec U , V
	Vec3 U(4, 2, 1);
	Vec3 V(2, 2, 1);

	// This is the assignment Vector Mag coords, I set them to floats, however ints work as well !
	// Vec V - Magnitude of V
	printf("[QUESTION] Magintude of Vector V(2,2,1)\n");  
	V.Mag();
	U.Mag();

	std::cout << std::endl;		// line break --> for easier reading
	
	// Vec V - Normalize V
	printf("[QUESTION] Normalize of Vector V(2,2,1) \n Note.... Magnitude Will Repeat Line(s) .... Answer is at end of repeated Mag() answer(s) .... This is for debugging purpose... Apologies for inconvenience\n");
	V.Normalize(2, 2, 1);
	
	std::cout << std::endl;		// line break --> for easier reading

	/// Dot Product
	std::cout << std::endl;
	printf("[QUESTION] Dot Product of V.U)\n");
	Vec3 DotProduct_question;
	DotProduct_question.DotProduct(V, U, 0);
	
	std::cout << std::endl;		// line break --> for easier reading
	
	printf("[QUESTION] Dot Product of A.B)\n");
	Vec3 A(2, 5, 1);
	Vec3 B(1, 0, -2);
	Vec3 AB_orth_question;
	AB_orth_question.DotProduct(A, B, 0);

	std::cout << std::endl;		// line break --> for easier reading
	
	printf("[QUESTION] Dot Product of C.D)\n");
	Vec3 C(2, 7, 1);
	Vec3 D(4, 0, 5);
	Vec3 AB_orth_question2;
	AB_orth_question2.DotProduct(C, D, 0);

	std::cout << std::endl;		// line break --> for easier reading

	printf("[QUESTION] Dot Product of E.F)\n");
	Vec3 E(1, 0, 2);
	Vec3 F(-1, -2, 4);
	Vec3 AB_orth_question3;
	AB_orth_question3.DotProduct(E, F, 0);



	std::cout << std::endl;		// line break --> for easier reading

	/// Cross Product
	printf("[QUESTION] Cross Product of U*V)\n");
	//V.CrossProduct(U , V , 1);		// Doesn't work This is using the magnitude , so come back to this !!
	//V.CrossProduct_2(U , V , 1);		// works
	V.CrossProduct_3(U , V);			// works

	std::cout << std::endl;		// line break --> for easier reading	


	/// ********************************************************************* END OF Vec3 ********************************************************************************************************************************** //

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
//                                                                              



	/// ********************************************************************* START OF Vec4 ********************************************************************************************************************************** //
	printf("START OF Vec4 \n");
	std::cout << std::endl;		// line break --> for easier reading

	Vec4 V4(2, 2, 1 ,1);
	Vec4 U4(4, 2, 1 ,1);
	
	// Store the Vec4 in a Vec3 Im trying to swizzle here, but not working, I wonder what Im missing come back to this !
	//Vec3 v(2, 2, 1);
	//Vec4 vv(2,2,1,1);
	//vv.Magnitude(vv.x , vv.y , vv.z);
	//Vec3 U3u4(U4);

	printf("Vec4 Magnitude V = %f\n" , V4.Magnitude(2, 2, 1));
	//V4.Magnitude(2, 2, 1);
	//printf("Vec4 U4 Magnitude = %f\n" , U4.Magnitude(4, 2, 1));

	std::cout << std::endl;		// line break --> for easier reading

	// So yeah I figured out who to finally swizzle the vec I do it in the Dot Product. 
	// I plan on neating this up when I return, for now even though I hate to say It, I have to do my other homework
	/// come back here !!!
	printf("Normalize Vec4 V \n");
	V4.Normalize_Vec4(2,2,1);

	std::cout << std::endl;		// line break --> for easier reading

	printf("Dot Product Vec4 V4.U4 \n");
	Vec4 dot_product_vec4_user;
	Vec3 v_(V4.x , V4.y , V4.z);
	Vec3 u_(U4.x , U4.y , U4.z);
	dot_product_vec4_user.DotProduct(v_, u_, 0);


	std::cout << std::endl;		// line break --> for easier reading


	printf("[QUESTION] Dot Product of Vec4 Test)\n");
	Vec3 G(4, 4, 4);
	Vec3 H(4, 4, 4);
	Vec3 AB_orth_question4;
	AB_orth_question4.DotProduct_2(G, H, 0);

	std::cout << std::endl;		// line break --> for easier reading

	printf("[QUESTION] Dot Product of Vec4 Test)\n");
	Vec3 I(1, 0, 2);
	Vec3 J(-1, -2, 4);
	Vec3 AB_orth_question5;
	AB_orth_question5.DotProduct_3(I, J, 0);

	std::cout << std::endl;		// line break --> for easier reading


	printf("[QUESTION] Cross Product of Vec4 Test)\n");
	Vec3 M(1, 0, 2);
	Vec3 N(-1, -2, 4);
	Vec3 AB_orth_question6;
	AB_orth_question6.CrossProduct_3(M, N);



	std::cout << std::endl;		// line break --> for easier reading

	printf("[QUESTION] Dot Product of Vec4 Test)\n");
	Vec3 O(-2, 1, 3);
	Vec3 P(5, 2, -1);
	Vec3 AB_orth_question7;
	AB_orth_question7.DotProduct_3(O, P , 0);
	
	std::cout << std::endl;		// line break --> for easier reading
	//O.operator*=(P);

	
	//std::cout << Q.x << " , " << Q.y << " , " << Q.z << std::endl;

	//Q.Mag();



	//*************************************************Test Block******************************************
	// MagnitudeVec
	Vec3 vecmagTest(3, 4, 12);
	Vec3 vecmag;
	vecmag.MagnitudeVec(vecmagTest);
	printf("VecMag Test\n");
	vecmagTest.print();	// 13
	

	// DotProductVec
	Vec3 DPV;
	Vec3 dotVecA(1, 1, 1);
	Vec3 dotVecB(2, 2, 2);

	DPV.DotProductVec(dotVecA, dotVecB , 2);


	///************************************************* Ray Block******************************************


	// Parametric
	//Vec3 paratmetricTest;
	//Vec3 paratmetricTestA(4,4,4);
	//Vec3 paratmetricTestB(2,2,2);
	//paratmetricTest.parametric(paratmetricTestA, paratmetricTestB, 2);
	std::cout << std::endl;

	// Distance Between Point and Line
	// V -> direction
	// Q -> Arbirtrary point
	// S - > starting Point
	// p(t) = s + tV
	// d = sqrt ( ||Q - s||^2 - [(Q-S) . V]^2 / ||V||  
	///Vec3 distancePL;
	///distancePL.DistanceFromPointToLine(Vec3(-3,0,6 ), Vec3(7, 2, 3), Vec3(1, 6, 0));
	
	/// Ray Class
	printf("Ray Class \n");
	Ray ray , rayQ , rayStart;
	Ray rayDirection , rQ;
	
	rayStart.SetStart(-3,0,6);				/// S Ray
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
	//float square_root_Add_all = sqrt((pow(2.0f, 2.0f) + (pow(4.0f, 2.0f) + (pow(6.0f, 2.0f)))));
	//
	//
	//float powA = pow(2.0f, 2);
	//float powB = pow(4.0f, 2);
	//float powC = pow(6.0f, 2);
	//
	//float answerPow = powA + powB + powC;
	//
	//float squareAnswerPow = sqrt(answerPow);
	//
	//std::cout << powA << std::endl;
	//std::cout << powB << std::endl;
	//std::cout << powC << std::endl;
	//std::cout << answerPow << std::endl;
	//std::cout << squareAnswerPow << std::endl;
	//std::cout << square_root_Add_all << std::endl;
	*/

	// Note 2.... This is just a test to check the math was working, prior to implimenting to a function, eventually i'll delete this, for now its just reference!
	/*
	//int x = 4;
	//x += 2;
	//Vec3 v(2, 4, 5);
	//// vec3 Normalize();
	//Vec3 N = v.Normalize();
	//
	//
	//Vec3 u(1, 2, 1);
	//Vec3 w = u + v;
	//w += u;// w=w+u;
	//std::cout << w.x << " " << w.y << " " << w.z << std:: endl;
   */
	
   ///															Quaternion
	//Quaternion quaternion_(2, 4, 6, 8);
	//quaternion_.print("Test quat");
	//Quaternion quaternion;
	//quaternion.print("Test quat 2");
	//Quaternion quatAdd(4,4,4,4);
	//Quaternion quatAdd1(1, 1, 1, 1);
	//quatAdd.operator+(quatAdd1);
	//quatAdd.print("quatAdd");
	//Quaternion quatVec4(77, 77, 77, 777);
	//quatVec4.getQuaternionVec4();
	//quatVec4.print("QuatVec4");
	//Quaternion quatVec3(25, 23, 25, 7);
	//quatVec3.getQuaternionVec3();
	//quatVec3.print("QuatVec3");
	//
	//Quaternion MUL;
	//Quaternion Mul1(1, 2, 2, 3);
	//Quaternion Mul2(2, 1, 2, 5);
	//Mul1.print("Mul1 = ");
	//Mul2.print("Mul2 = ");

	////MUL = Mul1.operator*(Mul2);
	////MUL.print("MUL = ");
	//std::cout << std::endl;

	//Vector3 v1(10,7,8);
	//Vector3 v2(2,10,4);
	//Vector3 vAnswer1;
	//v1.print("v1");
	//v2.print("v2");
	//Vector3 ev3;
	//ev3.print("Empty Vector init");
	//std::cout << std::endl;


	Quaternion v1(1, 2, 2, 3);
	Quaternion v2(2, 1, 2, 5);
	v1.print("v1 = ");
	v2.print("v2 = ");
	//times1.operator+(times2);
	v1.operator*(v2);
	//times1.print("Times one multipled");
	//times1.printVector3("Times one multipled ");

	



	


}

