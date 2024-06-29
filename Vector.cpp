// Samuel Fearnley n01047308 Math Lib Summer 2024
#include <iostream>
#include "Vector.h"
#include "cmath"
#include "math.h"
#include "sstream"


// Prints x , y ,z of Vec3 class
void Vec3::print()
{
	// print all the functions variables
	// debug 
	printf("[Debugger] Vector Class return print ");
	printf("(%f , %f , %f)\n", x, y, z);
}

void Vec3::print(std::string note)
{
	std::cout << note ;
	printf("(%f,%f,%f)\n", x, y, z);
}

// Returns the Vec3 Q for Distance To Point Equation , yes I have a print above that is SUPPOSED to do it, some 
// reason it wouldn't hence I have a duplicate. So yeah dont delete it unless you fix the earlier bug !
Vec3& Vec3::getVecQ()
{
	Vec3 Q(x, y, z);
	// debug //printf("[Debugger] Vector Class return Vec3 Q ");
	//printf("Vec Q (%f,%f,%f)\n", x, y, z);
	return Q;
}

// Set constructor variables
void Vec3::set(float x_, float y_, float z_)
{
	x = x_ ; //= 0;
	y = y_ ; //= 0;
	z = z_ ; //= 0;
}

// Default Constructor
Vec3::Vec3()
{
	set(1.0f, 1.0f, 1.0f);
}

// User Vector input constructor
Vec3::Vec3(const Vec3& v)
{
   set(v.x, v.y, v.z);
}

// User input constructor floats
Vec3::Vec3(float x, float y, float z)
{
	set(x, y, z);
}


/// magnitude 
// Magnitude of V is : 3
float Vec3::Mag(float x_, float y_, float z_)
{
	//std::cout << "Mag(float x , float y , float z) Vec(" << x_ << " ," << y_ << " ," << z_ << ") " << std::endl;
	float powX = pow(x_, 2);	//std::cout << "pow coord X = " << powX << std::endl;
	float powY = pow(y_, 2);	//std::cout << "pow coord Y = " << powY << std::endl;
	float powZ = pow(z_, 2);	//std::cout << "pow coord Z = " << powZ << std::endl;

	float AddPows = powX + powY + powZ;	//std::cout << "Add pow() X , pow() Y , pow() Z = " << AddPows << std::endl;

	float square_root_AddPows = sqrt(AddPows);
	std::cout << "[ANSWER] Magnitude of Vec(" << x_ << " ," << y_ << " ," << z_ << ") = " << square_root_AddPows << std::endl;

	return square_root_AddPows;
}
float Vec3::Mag()
{
	std::cout << "Mag() Vec(" << x << " ," << y << " ," << z << ") " << std::endl;
	float powX = pow(x, 2);	//std::cout << "pow coord X  = " << powX << std::endl;
	float powY = pow(y, 2);	//std::cout << "pow coord Y  = " << powY << std::endl;
	float powZ = pow(z, 2);	//std::cout << "pow coord Z  = " << powZ << std::endl;

	float AddPows = powX + powY + powZ;	//std::cout << "Add pow() X , pow() Y , pow() Z  = " << AddPows << std::endl;
	float square_root_AddPows = sqrt(AddPows);
	std::cout << "[ANSWER] Magnitude of Vec(" << x << " ," << y << " ," << z << ") = " << square_root_AddPows << std::endl; //printf("Magnitude V(2,2,1) = %f\n" , square_root_AddPows);//std::cout << "Square Root of AddPow(s) = " << square_root_AddPows << std::endl;

	return square_root_AddPows;
	//sqrt(x * x + y * y + z * z);
}
/// Return float Magnitude
float Vec3::Magnitude(float x_, float y_, float z_)
{
	//std::cout << "Mag() Vec(" << x_ << " ," << y_ << " ," << z_ << ") " << std::endl;
	float powX = pow(x_, 2);	//std::cout << "pow coord X  = " << powX << std::endl;
	float powY = pow(y_, 2);	//std::cout << "pow coord Y  = " << powY << std::endl;
	float powZ = pow(z_, 2);	//std::cout << "pow coord Z  = " << powZ << std::endl;

	float AddPows = powX + powY + powZ;	//std::cout << "Add pow() X , pow() Y , pow() Z  = " << AddPows << std::endl;
	float square_root_AddPows = sqrt(AddPows);
	//std::cout << "[ANSWER] Magnitude of Vec(" << x_ << " ," << y_ << " ," << z_ << ") = " << square_root_AddPows << std::endl; //printf("Magnitude V(2,2,1) = %f\n" , square_root_AddPows);//std::cout << "Square Root of AddPow(s) = " << square_root_AddPows << std::endl;

	return square_root_AddPows;
}
/// Return Mag Without Square Root , For Finding Distance Between Point & A Line
float Vec3::MagnitudeDistance(float x_, float y_, float z_)
{
	//std::cout << "Mag() Vec(" << x_ << " ," << y_ << " ," << z_ << ") " << std::endl;
	float powX = pow(x_, 2);	//std::cout << "pow coord X  = " << powX << std::endl;
	float powY = pow(y_, 2);	//std::cout << "pow coord Y  = " << powY << std::endl;
	float powZ = pow(z_, 2);	//std::cout << "pow coord Z  = " << powZ << std::endl;

	float AddPows = powX + powY + powZ;	//std::cout << "Add pow() X , pow() Y , pow() Z  = " << AddPows << std::endl;
	//float square_root_AddPows = sqrt(AddPows);
	//printf("[Debugger} MagnitudeDistance (%f) \n", AddPows);
	return AddPows;
}
/// Return Vec Magnitude 
Vec3& Vec3::MagnitudeVec(Vec3& vecA)
{
	// ||M|| = sqrt((x^2 + y ^2 + z^2))
	//printf("******************Magnitude**************\n");
	int powvecX = pow(vecA.x, 2);
	int powvecY = pow(vecA.y, 2);
	int powvecZ = pow(vecA.z, 2);
	//printf("Final float Squared Mag (%f,%f,%f)\n", (float)powvecX, (float)powvecY, (float)powvecZ);
	//printf("Final int Squared Mag (%i,%i,%i)\n", powvecX, powvecY, powvecZ);
	
	int intMag = sqrt((powvecX + powvecY + powvecZ));
	//float floatMag = sqrt((powvecX + powvecY + powvecZ));
	//printf("Final int Mag (%i)\n", intMag);
	//printf("Final Float Mag (%f)\n", floatMag);
	
	vecA.x = intMag;
	vecA.y = intMag;
	vecA.z = intMag;

	Vec3 returnMagVec(vecA.x, vecA.y, vecA.z);
	//printf("int VecMag return (%f,%f,%f)\n", (float)vecA.x, (float)vecA.y, (float)vecA.z);
	//printf("float VecMag return (%i,%i,%i)\n", (int)vecA.x, (int)vecA.y, (int)vecA.z);
	//printf("********************************************\n");
	return returnMagVec;
}



/// normalize
// Normalized V is : (0.667, 0.667, 0.334)
Vec3 Vec3::Normalize(float x , float y , float z)
{
	//std::cout << "Vec(" << x << " , " << y << " , " << z << std::endl;
	x /= Mag();
	y /= Mag();
	z /= Mag();

	std::cout << std::endl;
	printf("[ANSWER] Normalized Vec  = (%f,%f,%f) \n", x, y, z);
	Vec3 Norm(x, y, z);
	return Norm;
}
Vec3 Vec3::Normalize()
{
	//std::cout << "Vec(" << x << " , " << y << " , " << z << std::endl;
	x / Mag();
	y / Mag();
	z / Mag();

	Vec3 Norm(x, y, z);
	std::cout << "Vec (" << x << " , " << y << " , " << z << ") Normalized = " << std::endl;
	return Norm;
}
float Vec3::Normalize_Vec4(float x_ , float y_ , float z_)
{	
	int fvx, fvy, fvz;
	int vx, vy, vz;
	int addvxyz;
	int sqrtvxyz;
	int magnitude_;
	vx = (pow(x_, 2));		// 4
	vy = (pow(y_, 2));		// 4
	vz = (pow(z_, 2));		// 1
	
	addvxyz = vx += vy += vz;
	sqrtvxyz = sqrt(addvxyz);
	magnitude_ = sqrtvxyz;
	printf("Normal Mag Calculation = %i", magnitude_);

	x_ /= magnitude_;
	y_ /= magnitude_;
	z_ /= magnitude_;

	Vec3 Mag3(x_, y_, z_);
	Vec4 Mag4(x_, y_, z_ , 0);
	std::cout << "[ANSWER] Normalized Vec =  (" << x_ << " , " << y_ << " , " << z_ << ")" << std::endl;
	return x_, y_, z_;
}


/// Dot product V.U is : 13
/// Dot Product Using Angle Theta, 
float Vec3::DotProduct(Vec3& a, Vec3& b, float angle_theta)
{
	// 4D Dot Product Formula (a1)(b1) + (a2)(b2) + (a3)(b3) + (a4)(b4) + (aN)(bN)
	// 3D Dot Product Formula  A.B = ||A|| x ||B|| X cos(angle_theta)
 	// a1	// b1
	// a2	// b2
	// a3 	// b3
	printf("Vector A = (%f , %f , %f)\nVector B = (%f , %f , %f)\nAngle Theta = (%f)\n", a.x , a.y , a.z , b.x , b.y , b.z , angle_theta);
	static float a1, a2, a3, b1, b2, b3;

	// SET FLOAT VARIABLES FOR MAGNITUDE ANSWERS
	float MagA; float MagB;

	// GATHER MAGNITUDE OF VEC A && VEC B
	MagA = Magnitude(a.x, a.y, a.z);		// == 3
	MagB = Magnitude(b.x, b.y, b.z);		// == 4.58258

	// MULTIPLY MAG A && MAG B && THE COS(ANGLE THETA)
	// SET FLOAT TO RETURN DOT PRODUCT --> TWO ARE SET, ONE RETURNS AN INT, ONE RETURNS A FLOAT, THE INT IS RETURNING IN THIS CASE
	// NOTE.... WHEN I REMOVE THE THETA ANGLE IT WORKS, AND RETURNS THE ANSWER ASKED FOR 13 IF I CALCULATE THETA AS 1 IT RETURNS 7 , THERFORE THE ANGLE THETA INSIDE MAIN WILL BE SET TO 0
	float Dot_Product_return;
	Dot_Product_return = MagA *= MagB * cos(angle_theta);


	// SET A VARIABLE FOR COS(ANGLE_THETA) , THEN MULTIPLY THE ANSWER OF ||MagA|| X ||MagB||
	float cos_angle_theta = cos(angle_theta);
	Dot_Product_return *= cos_angle_theta;



	int Dot_Product_return_int = Dot_Product_return;
	Vec3 Dot_Product_Vector();
	
	// PRINT THE ANSWER OF DOT PRODUCT
	//printf("[ANSWER] Dot Product of VecA(%f,%f,%f) & VecB(%f,%f,%f) = %f\n", a.x, a.y, a.z, b.x, b.y, b.z, Dot_Product_return);
	printf("[ANSWER] Dot Product of VecA(%f,%f,%f) & VecB(%f,%f,%f) = %i\n", a.x, a.y, a.z, b.x, b.y, b.z, Dot_Product_return_int);
	
	return Dot_Product_return;
}
Vec3& Vec3::DotProduct_2(Vec3& a, Vec3& b, float angle_theta)
{
	// I find all this so pointless, I should be able to just use the function paramater, but 
	// when I did prior I had an error in terms of printing the wrong vectors, 
	// then the math would be off
	int ax, ay, az, bx, by, bz;
	ax = a.x;
	ay = a.y;
	az = a.z;
	
	bx = b.x;
	by = b.y;
	bz = b.z;

	// Dot is defined as (ax)(bx)+(ay)(by)+(az)(bz)
	int a1 = ax *= bx;
	int a2 = ay *= by;
	int a3 = az *= bz;
	
	Vec3 DotDefined(a1, a2, a3);
	printf("Vector of Dot Defined = \n");
	std::cout << DotDefined.x << " , " << DotDefined.y << " , " << DotDefined.z << std::endl;

	int Dot_defined = a1 += a2 += a3;
	printf("a1 += a2 += a3 = %i \n", Dot_defined);

	float Dot_defined_sqaure_root = 
	sqrt((float)Dot_defined);

	printf("Square Root of added Vecs %f \n", Dot_defined_sqaure_root);

	float finalAX, finalAY, finalAZ;
	finalAX = a.x /= Dot_defined_sqaure_root;
	finalAY = a.y /= Dot_defined_sqaure_root;
	finalAZ = a.z /= Dot_defined_sqaure_root;
	
	std::cout << finalAX << std::endl;

	Vec3 finalA(a.x, a.y, a.z);
	Vec3 finala(finalAX, finalAY, finalAZ);
	//printf("FinalA (%i,%i,%i) \n", a.x, a.y, a.z);
	std::cout << a.x << " , " << a.y << " , " << a.z << std::endl;

	float finalBX, finalBY, finalBZ;
	finalBX = b.x /= Dot_defined_sqaure_root;
	finalBY = b.y /= Dot_defined_sqaure_root;
	finalBZ = b.z /= Dot_defined_sqaure_root;
	
	std::cout << finalBX << std::endl;


	Vec3 finalB(b.x, b.y, b.z);
	//printf("FinalA (%i,%i,%i) \n", b.x, b.y, b.z);
	std::cout << b.x << " , " << b.y << " , " << b.z << std::endl;
	
	return *this;
}
/// BEST WORKING DOT PRODUCT THIS IS HOW IT SHOULDVE BEEN FROM THE START !! MAY 18 8:24pm
Vec3& Vec3::DotProduct_3(Vec3& a, Vec3& b, float angle_theta)
{
	// Store Copy of original Vectors
	float Ax, Ay, Az, Bx, By, Bz;
	Ax = a.x; Ay = a.y; Az = a.z;		// Vec a
	Bx = b.x; By = b.y; Bz = b.z;		// Vec b

	// Vec a
	a.x = pow(a.x, 2);
	a.y = pow(a.y, 2);
	a.z = pow(a.z, 2);
	// print for debugging
	std::cout << a.x << " , " << a.y << " , " << a.z << std::endl;

	float magA = sqrt(a.x += a.y += a.z);
	std::cout << "MagA = " <<  magA << std::endl;

	// Divide Original Vector componenets by Magnitude , Store them in new float variable
	// Print out to ensure the Vector has been divided correctly
	float magAx, magAy, magAz;

	magAx = Ax /= magA;
	magAy = Ay /= magA;
	magAz = Az /= magA;
	std::cout << magAx << " , " << magAy << " , " << magAz << std::endl;

	// Vec b
	b.x = pow(b.x, 2);
	b.y = pow(b.y, 2);
	b.z = pow(b.z, 2);
	// print for debugging
	std::cout << b.x << " , " << b.y << " , " << b.z << std::endl;

	float magB = sqrt(b.x += b.y += b.z);
	std::cout << "MagB = " << magB << std::endl;
	float magBx, magBy, magBz;
	magBx = Bx /= magB;
	magBy = By /= magB;
	magBz = Bz /= magB;
	std::cout << magBx << " , " << magBy << " , " << magBz << std::endl;
	
	Vec3 VectorB(magBx, magBy, magBz);
	std::cout << magBx << " , " << magBy << " , " << magBz << std::endl;

	Vec3 VectorA(magAx, magAy, magAz);
	std::cout << magAx << " , " << magAy << " , " << magAz << std::endl;

	Vec3 VecAB = VectorA *= VectorB;
	std::cout << VecAB.x << " , " << VecAB.y << " , " << VecAB.z << std::endl;


	return *this;
}
/// 2. Dot Product Keep
Vec3& Vec3::DotProductVec(Vec3& vecA, Vec3& vecB, float cosTheta)
{
	//printf("**********************************Dot Product******************************************\n");
	if (!cosTheta)
	{
		cosTheta = 0;
	}
	// Get The Mag , Long Hand ....
	int powvecAX = pow(vecA.x, 2);
	int powvecAY = pow(vecA.y, 2);
	int powvecAZ = pow(vecA.z, 2);

	int powvecBX = pow(vecB.x, 2);
	int powvecBY = pow(vecB.y, 2);
	int powvecBZ = pow(vecB.z, 2);

	// Add Squared Components VecA , VecB 
	float addVecB = powvecBX + powvecBY + powvecBZ;
	float addVecA = powvecAX + powvecAY + powvecAZ;
	// debug
	printf("VecA pow(s) = %f \n VecB pow(s) = % f \n", addVecA , addVecB);

	// Square Root VecA , VecB
	float sqrtVecA = sqrt(addVecA);
	float sqrtVecB = sqrt(addVecB);
	// debug
	printf("sqrt(VecA)= %f\nsqrt(VecB)= %f \n", sqrtVecA, sqrtVecB);

	// Final Magnitude VecA , VecB
	float VecA_FinalMag = sqrtVecA;
	float VecB_FinalMag = sqrtVecB;
	// debug
	printf("||VecA|| = %f\n||VecB|| = %f\ncosTheta = %f\n", VecA_FinalMag, VecB_FinalMag , cosTheta);

	// Final Dot Product Multiply ||VecA|| ||VecB|| angle
	float VecA_VecBDotProduct = VecA_FinalMag * VecB_FinalMag * cosTheta; 
	// debug
	float VecABDot = VecA_VecBDotProduct;
	//printf("||%f|| * ||%f|| * %f = %f\n", VecA_FinalMag,VecB_FinalMag,cosTheta, VecABDot);
	//printf("**********************************Dot Product******************************************\n");
	printf("Dot Product Return = %f\n",VecABDot);
	//printf("***************************************************************************************\n");
	// return
	Vec3 dotProdretrun(VecABDot , VecABDot , VecABDot); return dotProdretrun;
}


// 4:20 Dot Prod
float Vec3::DotProd(Vec3& a, Vec3& b)
{
	float abX = a.x * b.x;
	float abY = a.y * b.y;
	float abZ = a.z * b.z;

	float dot = abX + abY + abZ;
	return dot;
	//return Dot;
}

/// Cross product UxV is : (0, -2, 4)
// CrossProductVec
Vec3& Vec3::CrossProductVec(Vec3& A, Vec3& B, double sinTheta)
{

	Vec3 crossprodreturn; return crossprodreturn;
}
// cross product
float Vec3::CrossProduct(const Vec3& v, const Vec3& b, float theta)
{
	// its exactly what it sounds, i cant beleive i forgot the formula.
	// ||vecA|| *= ||vecb|| *= sin(theta) , lol geometric , why did I apply this 0_0 , I'm gonna keep this though just in case, you never know!


	float mag1 = Mag(v.x, v.y, v.z);
	float mag2 = Mag(b.x, b.y, b.z);

	std::cout << "Vec3 V(" << v.x << " ,  " << v.y << " ,  " << v.z << ") Vec3 b(" << b.x << " ,  " << b.y << " ,  " << b.z << ")" << " Angle Theta = " << theta << std::endl;
	std::cout << "||V|| = (" << mag1 << ") ||B|| = (" << mag2 << ") Angle Theta = " << theta << std::endl;

	float Cross_Product_Answer;
	Cross_Product_Answer = mag1 *= mag2 *= sin(theta);
	std::cout << "||V|| x ||B|| x AngleTheta = " << Cross_Product_Answer << std::endl;
	std::cout << "[Cross Product] = " << Cross_Product_Answer << std::endl;

	std::cout << x << y << z << std::endl;
	return Cross_Product_Answer;

}
//Cross product UxV is : (0, -2, 4) , WORKING FINISHED 12:44AM May 15 , needs to be tested again !
Vec3& Vec3::CrossProduct_2(Vec3& v, Vec3& b, double theta)
{											 // U  // V
	// Ux  *=  // Vx // (vy)(bz) - (vz)(by)  // 4  // 2
	// Uy  *=  // Vy // (vx)(bz) - (vz)(bx)  // 2  // 2
	// Uz  *=  // Vz // (vx)(by) - (vy)(bx)  // 1  // 1

	// x1	// x2	// Eq 1. (y1)(z2) - (z1)(y2)
	// y1	// y2	// Eq 2. (z1)(x2) - (x1)(z2) 
	// z1	// z2	// Eq 3. (x1)(y2) - (y1)(x2)



	// Vector copies
	// Notes , so I had to separate the vectors , in order for them to be called separate, and not be
	// copied into each new equation inside the scope. 
	// I'm not a fan of how this is written, there must be a simpler way, hence why I wrote a float x,y,z function
	// yet to use it though, for now this works, I need a break, my head hurts, and I know I'm overlooking something so simple
	/// Come back here !! As of 10:26PM Thursday May 16 , 2024 This function relays the correct answer (0,-2,4)
	// perhaps set three seperate matrices, to call on their own, leaving the original intact, exclude copying inside scope
	// perhaps make an array ? return the coords into an array, then retrive via index, will the index remain the same or will they change ? , come back to this !
	int a1, a2, a3, b1, b2, b3;
	a1 = v.x; // = 4;  
	a2 = v.y; // = 2; 
	a3 = v.z; // = 1;
	b1 = b.x; // = 2;  
	b2 = b.y; // = 2; 
	b3 = b.z; // = 1;

	int u1, u2, u3, v1, v2, v3;
	u1 = v.x;  //= 4;
	u2 = v.y;  //= 2;
	u3 = v.z;  //= 1;
	v1 = b.x;  //= 2;
	v2 = b.y;  //= 2;
	v3 = b.z;  //= 1;

	std::cout << "Original Vec Coords" << std::endl;
	std::cout << "v.x " << v.x << std::endl;
	std::cout << "v.y " << v.y << std::endl;
	std::cout << "v.z " << v.z << std::endl;
	std::cout << "b.x " << b.x << std::endl;
	std::cout << "b.y " << b.y << std::endl;
	std::cout << "b.z " << b.z << std::endl;

	// Line Break
	std::cout << std::endl;

	// Eq 1
	// 2 * 1 = 2 ,  1 * 2 = 2  , 2 - 2 = 0
	col1f = a2 *= b3;
	col2f = a3 *= b2;
	std::cout << "v.x " << a1 << std::endl;
	std::cout << "v.y " << a2 << std::endl;
	std::cout << "v.z " << a3 << std::endl;
	std::cout << "b.x " << b1 << std::endl;
	std::cout << "b.y " << b2 << std::endl;
	std::cout << "b.z " << b3 << std::endl;
	std::cout << col1f << " -= " << col2f << std::endl;
	Col1minusCol2 = col1f -= col2f;
	std::cout << Col1minusCol2 << std::endl;

	// Line Break
	std::cout << std::endl;

	/// this is the ugliest way to code it, im not proud of this, please fix this when you find time !!
	// Eq 2
	// 4 * 1 ,  1 * 2 ,  2 - 4 = -2 
	col3f = a1 *= b3;
	col4f = v.z *= b1;
	std::cout << "v.x " << a1 << std::endl;
	std::cout << "v.y " << a2 << std::endl;
	std::cout << "v.z " << a3 << std::endl;
	std::cout << "b.x " << b1 << std::endl;
	std::cout << "b.y " << b2 << std::endl;
	std::cout << "b.z " << b3 << std::endl;
	std::cout << col3f << " -= " << col4f << std::endl;
	Col3minusCol4 = col4f -= col3f;
	std::cout << Col3minusCol4 << std::endl;

	// Line Break
	std::cout << std::endl;

	// Eq 3
	colf5 = u1 *= v2;
	colf6 = u2 *= v1;
	std::cout << "u.x " << u1 << std::endl;
	std::cout << "u.y " << u2 << std::endl;
	std::cout << "u.z " << u3 << std::endl;
	std::cout << "v.x " << v1 << std::endl;
	std::cout << "v.y " << v2 << std::endl;
	std::cout << "v.z " << v3 << std::endl;
	std::cout << colf5 << " -= " << colf6 << std::endl;
	Col5minusCol6 = colf5 -= colf6;
	std::cout << Col5minusCol6 << std::endl;

	// Line Break
	std::cout << std::endl;

	// Print && return Cross Product
	Vec3 Norm(Col1minusCol2, Col3minusCol4, Col5minusCol6);
	std::cout << " [ANSWER] Cross Product VecA , VecB " << "(" << Col1minusCol2 << " , " << Col3minusCol4 << " , " << Col5minusCol6 << ")" << std::endl;
	//return col1f , col2f , col3f;
	return Norm;

}
//Cross product UxV is : (0, -2, 4) , WORKING FINISHED 12:44AM May 17 --> Theta isn't included here !
Vec3& Vec3::CrossProduct_3(Vec3& x, Vec3& y)	// float
{
	// Cross Produce Formula ||A|| * ||B|| * sin(Theta)
	// x1   // x2	// Eq 1. (y1)(z2) - (z1)(y2)
	// y1   // y2	// Eq 2. (z1)(x2) - (x1)(z2)	// flipped (x1)(z2) == (z1)(x2), inverse ?
	// z1   // z2	// Eq 3. (x1)(y2) - (y1)(x2)	

	// SET THE VECTORS TO THEIR RESPECTIVE MATRIX COPIES
	// Yuck.... MUST BE A BETTER WAY TO DO THIS....
	float x1, y1, z1, x2, y2, z2;
	float xx1, yy1, zz1, xx2, yy2, zz2;
	float xxx1, yyy1, zzz1, xxx2, yyy2, zzz2;

	// for Eq 1
	x1 = x.x;	x2 = y.x;	// x1   // x2
	y1 = x.y;	y2 = y.y;	// y1   // y2
	z1 = x.z;	z2 = y.z;	// z1   // z2
	// for Eq 2
	xx1 = x.x;	xx2 = y.x;	// x1   // x2
	yy1 = x.y;	yy2 = y.y;	// y1   // y2
	zz1 = x.z;	zz2 = y.z;	// z1   // z2
	// for Eq 3
	xxx1 = x.x;	xxx2 = y.x;	// x1   // x2
	yyy1 = x.y;	yyy2 = y.y;	// y1   // y2
	zzz1 = x.z;	zzz2 = y.z;	// z1   // z2

	// PRINT OUT THE VECTOR MATRIX TO SHOW , MAINLY FOR DEBUGGING PURPOSE

	std::cout << "Vector Input Vec(x) " << x.x << " , " << x.y << " , " << x.z << std::endl;
	std::cout << "Vector Input Vec(y) " << y.x << " , " << y.y << " , " << y.z << std::endl;

	printf("Newly Set Copy Vector Matrix(s) x1 && x2\n");
	std::cout << " x1 = " << x1 << " x2 = " << x2 << std::endl;			// x1   // x2
	std::cout << " y1 = " << y1 << " y2 = " << y2 << std::endl;			// y1   // y2
	std::cout << " z1 = " << z1 << " z2 = " << z2 << std::endl;			// z1   // z2

	printf("Newly Set Copy Vector Matrix(s) xx1 && xx2\n");
	std::cout << " xx1 = " << xx1 << " xx2 = " << xx2 << std::endl;		// x1   // x2
	std::cout << " yy1 = " << yy1 << " yy2 = " << yy2 << std::endl;		// y1   // y2
	std::cout << " zz1 = " << zz1 << " zz2 = " << zz2 << std::endl;		// z1   // z2

	printf("Newly Set Copy Vector Matrix(s) xxx1 && xxx2\n");
	std::cout << " xxx1 = " << xxx1 << " xxx2 = " << xxx2 << std::endl;		// x1   // x2
	std::cout << " yyy1 = " << yyy1 << " yyy2 = " << yyy2 << std::endl;		// y1   // y2
	std::cout << " zzz1 = " << zzz1 << " zzz2 = " << zzz2 << std::endl;		// z1   // z2
	std::cout << std::endl; // space between equations for easier console reading



	// EQUATIONS USING THE FLOAT SET VAR(S) SET TO THE INPUT VECTORS. NOTE... IN PREVIOUS TEST INT WAS USED INSTEAD OF FLOAT
	// Eq 1. (y1)(z2) - (z1)(y2)
	float eq1_part1 = y1 *= z2;
	printf("Eq1.p1 %f\n", eq1_part1);
	float eq1_part2 = z1 *= y2;
	printf("Eq1.p2 %f\n", eq1_part2);
	float Eq1 = eq1_part1 -= eq1_part2;
	printf("Eq1 = %f\n", Eq1);
	std::cout << std::endl; // space between equations for easier console reading

	// Eq 2. (z1)(x2) - (x1)(z2) ---> Calling Copy Matrix #2 xx1 && xx2
	float eq2_part1 = zz1 *= xx2;
	printf("Eq2.p1 = %f\n", eq2_part1);
	float eq2_part2 = xx1 *= zz2;
	printf("Eq2.p2 = %f\n", eq2_part2);
	float Eq2 = eq2_part1 -= eq2_part2;
	printf("Eq2 = %f\n", Eq2);
	std::cout << std::endl; // space between equations for easier console reading

	// Eq 3. (x1)(y2) - (y1)(x2) --> here I make a 3rd Matrix copy
	float eq3_part1 = xxx1 *= yyy2;
	printf("Eq3.p1 = %f \n", eq3_part1);
	float eq3_part2 = yyy1 *= xxx2;
	printf("Eq3.p2 = %f \n", eq3_part2);
	float Eq3 = eq3_part1 -= eq3_part2;
	printf("Eq3 = %f \n", Eq3);

	// RETURN THE COORDS IN FLOAT VALUES IN VECTOR FORMAT
	// Float Value Return
	Vec3 Cross_Prodoct_Return(Eq1, Eq2, Eq3);
	printf("[ANSWER] Cross Product Final Vector [float] =( %f , %f , %f )\n", Eq1, Eq2, Eq3);

	// SET EQ ANSWERS TO INT && RETURN THE VECTOR COORDS PRODUCT AS INT(S)
	int Eq_1 = Eq1;
	int Eq_2 = Eq2;
	int Eq_3 = Eq3;

	//RETURN THE COORDS IN INT VALUES IN VECTOR FORMAT
	Vec3 Cross_Product_Return_int(Eq_1, Eq_2, Eq_3);
	printf("[ANSWER] Cross Product Final Vector [int] =( %i , %i , %i )\n", Eq_1, Eq_2, Eq_3);


	// RETURN CROSS PRODUCT --> THERE IS A INT RETURN && A FLOAT RETURN
	// NOTE.... SHOULD I OVERLOAD MAKE ANOTHER FUNCTION BUT INT INSTEAD? COME BACK TO THIS ....
	//return Cross_Prodoct_Return;
	return Cross_Product_Return_int;

}


/// Operator(s)
Vec3& Vec3::operator=(const Vec3& v)
{
	set(v.x, v.y, v.z);
	return *this;
}
// Add
const Vec3& Vec3::operator+(const Vec3& v) const
{
	//std::cout << "VecA + VecB  = " << x << " ," << y << " ," << z << std::endl;
	return Vec3
	(
		x + v.x,
		y + v.y,
		z + v.z
		
	);
}
Vec3& Vec3::operator+=(const Vec3& v)
{
	//std::cout << "VecA += VecB = " << x << " ," << y << " ," << z << std::endl;
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
	
}
/// subtract 
// overload the – operator to also subtract vectors
const Vec3& Vec3::operator - (const Vec3& v) const
{
	//std::cout << "VecA - VecB  = " << x << " ," << y << " ," << z << std::endl;
	return Vec3
	(
		x - v.x,
		y - v.y,
		z - v.z

	);

}
Vec3& Vec3::operator-= (const Vec3& v)
{
	//std::cout << "VecA -= VecB = " << x << " ," << y << " ," << z << std::endl;
	    x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
}
/// multiplication - operator
const Vec3& Vec3::operator * (const Vec3& v)
{
	//std::cout << "VecA * VecB  = " << v.x << " ," << v.y << " ," << v.z << std::endl;
	//std::cout << "VecA * VecB  = " << x << " ," << y << " ," << z << std::endl;
	return Vec3
	(
		x * v.x,
		y * v.y,
		z * v.z

	);




}
Vec3& Vec3::operator *= (const Vec3& v)
{
	x *= v.x, y *= v.y, z *= v.z;
	//std::cout << "VecA *= VecB = " << x << " ," << y << " ," << z << std::endl;
	return *this;
}




///////////////////////////Test Functions
/// Dot Product No angle , For Find Distance between Point & Line , Long Hand Format
float Vec3::DotProductDistance(Vec3& a, Vec3& b)
{
	static float Ax, Ay, Az, Bx, By, Bz;
	float dotDistance = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	printf("dotDistance = %f\n", dotDistance);
	return dotDistance;
}
/// Distance between A Point and a Line || Q - S|| returns a Vector
Vec3 Vec3::Q_Minus_S(const Vec3& V, const Vec3& v) const
{
	/// Subtract Vectors
	Vec3 Vv = Vec3(V.x - v.x, V.y - v.y, V.z - v.z);
	
	// Debug //std::cout << "VecSub = " << Vv.x << "," << Vv.y << "," << Vv.z << std::endl;

	
	// Debug //printf("Q-S = %f\n",Vvv);

	return Vv;

}
/// Distance between A Point and a Line || Q - S|| ^ 2	 returns a float
float Vec3::Q_Minus_S_Squared(const Vec3& V , const Vec3& v) const
{
	/// Subtract Vectors
	Vec3 Vv = Vec3(V.x - v.x, V.y - v.y, V.z - v.z);
	
	// debug //std::cout << "VecSub = " << Vv.x << "," << Vv.y << "," << Vv.z << std::endl;
	
	/// Square Vector x,y,z
	float Vvx = pow(Vv.x, 2);
	float Vvy = pow(Vv.y, 2);
	float Vvz = pow(Vv.z ,2);
	// debug std::cout << "VecSub = " << Vvx << "," << Vvy << "," << Vvz << std::endl;

	/// Add Vector x,y,z Up
	float Addxyz = Vvx + Vvy + Vvz;
	
	// Debug //printf("Added Vectors xyz = %f\n", Addxyz);

	return Addxyz;

}
/// Parametric Eq test 
float Vec3::parametric(Vec3 A, Vec3 B, float t)
{
	// pt = S + tV
	// p(t) = P0 + tV
	Vec3 P0 = A;
	Vec3 P1 = B;
	Vec3 V;

	std::cout << "P0 :: " << A.x << " , " << A.y << " , " << A.z << std::endl;
	std::cout << "P1 :: " << B.x << " , " << B.y << " , " << B.z << std::endl;
	if (t == 0)
	{
		t = 1.0f;
		printf("t set to = %f\n", t);
	}
	else printf("t set to = %f\n", t);
	
		// Find V p2 - p1
		V = P1 - P0;

	std::cout << "Find V " << V.x << "," << V.y << "," << V.z << std::endl;
	
	//p(t) = P0 + tV
	// multiply t by vector V
	Vec3 TV = Vec3(V.x * t, V.y * t, V.z * t);
	std::cout << "Multiply t by V " << TV.x << "," << TV.y << "," << TV.z << std::endl;
	
	TV = A;
	V = B;
	
	// P0 + tV
	Vec3 Pt = P0 + TV;
	std::cout << "Pt = P0 + tV = " << Pt.x << "," << Pt.y << "," << Pt.z << std::endl;

	return Pt.x , Pt.y , Pt.z;
	
	//float Vx, Vy, Vz;
	//Vx = V.x * t;
	//Vy = V.y * t;
	//Vz = V.z * t;
	//printf("PPP = (%f,%f,%f) \n", Vx, Vy, Vz);
	//
	//
	//Vec3 PP = Vec3(P0.x, P0.y, P0.z);
	//Vec3 PPP = Vec3(Vx , Vy, Vz);
	//printf("PP = (%f,%f,%f) \n", PP.x, PP.y, PP.z);
	//printf("V = (%f,%f,%f) \n", V.x, V.y, V.z);

	//Vec3 PPPPP = PP + PPP;
	//printf("PPP = (%f,%f,%f) \n", PPP.x, PPP.y, PPP.z);

	//printf("p(t) + P0 * tV = %f \n" , P);

}
float Vec3::DistanceFromPointToLine(Vec3 Point_Start, Vec3 Point_End , Vec3 Q_arbitrary)
{

	// Q
	Vec3 Q_point = Q_arbitrary;
	std::cout << "Q  = " << Q_point.x << "," << Q_point.y << "," << Q_point.z << std::endl;
	// S --> Start Point P1
	Vec3 pointStart = Point_Start;
	std::cout << "P1 = " << pointStart.x << "," << pointStart.y << "," << pointStart.z << std::endl;
	//	--> end Point P2
	Vec3 pointEnd = Point_End;
	std::cout << "P2 = " << pointEnd.x << "," << pointEnd.y << "," << pointEnd.z << std::endl;
	std::cout << std::endl;
	// P(t) = S + tV

	/// Find V		// testing <10,2,-3>
	// formula :: V = P2 - P1							
	Vec3 Vdirection = pointEnd - pointStart;
	printf("Vdirection = \n"); 
	Vdirection.print();			

	/// Find V Mag	// testing 113.0
	// formula :: ||V||^2
	// Note ... Remember to find the float , we are finding distance !
	//MagnitudeVec(Vdirection);
	float VMag = MagnitudeDistance(Vdirection.x, Vdirection.y, Vdirection.z);
	printf("VMag = %f\n" , VMag); 

	/// ||Q-S||
	Vec3 QminusS = Q_Minus_S(Q_point, pointStart);
	printf("Q-S = (%f,%f,%f)\n", QminusS.x, QminusS.y, QminusS.z);


	/// ||Q - S|| ^ 2
	float QS_Squared = Q_Minus_S_Squared(Q_point, pointStart);
	printf("Q - S ^ 2 = %f\n" , QS_Squared);

	/// [(Q-S) . V] ^2

	DotProductVec(QminusS, Vdirection, 0);


	return 0.0f;
}



/// ****************************************************** Vec4 class 
// Set constructor variables
void Vec4::set(float x_, float y_, float z_, float w_)
{
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}

/// Default Constructor
Vec4::Vec4()
{
	set(1.0f, 1.0f, 1.0f , 1.0f);
}

/// User Vector input constructor
Vec4::Vec4(const Vec4& v)
{
	set(v.x , v.y , v.z , v.w);
}

/// User input constructor floats
Vec4::Vec4(float x, float y, float z, float w)
{
	set(x, y, z, w);
}

float Vec4::Mag(float x , float  y , float z , float w)	
{
	//std::cout << "Mag() Vec(" << x_ << " ," << y_ << " ," << z_ << ") " << std::endl;
	float powX = pow(x, 2);	//std::cout << "pow coord X  = " << powX << std::endl;
	float powY = pow(y, 2);	//std::cout << "pow coord Y  = " << powY <<std::endl;
	float powZ = pow(z, 2);	//std::cout << "pow coord Z  = " << powZ << std::endl;
	float powW = pow(w, 2);	//std::cout << "pow coord Z  = " << powZ << std::endl;

	float AddPows = powX + powY + powZ + powW;	//std::cout << "Add pow() X , pow() Y , pow() Z  = " << AddPows << std::endl;
	float square_root_AddPows = sqrt(AddPows);
	//std::cout << "[ANSWER] Magnitude of Vec(" << x_ << " ," << y_ << " ," << z_ << ") = " << square_root_AddPows << std::endl; //printf("Magnitude V(2,2,1) = %f\n" , square_root_AddPows);//std::cout << "Square Root of AddPow(s) = " << square_root_AddPows << std::endl;

	return square_root_AddPows;
}

Vec4 Vec4::Normalize(float x, float  y, float z, float w)
{
	int fvx, fvy, fvz , fvw;
	int vx, vy, vz , vw;
	int addvxyzw;
	int sqrtvxyzw;
	int magnitude_;
	vx = (pow(x, 2));		// 4
	vy = (pow(y, 2));		// 4
	vz = (pow(z, 2));		// 1
	vw = (pow(w, 2));		// 1

	addvxyzw = vx += vy += vz += vw ;
	sqrtvxyzw = sqrt(addvxyzw);
	magnitude_ = sqrtvxyzw;
	printf("Normal Mag Calculation = %i", magnitude_);

	x /= magnitude_;
	y /= magnitude_;
	z /= magnitude_;
	w /= magnitude_;

	Vec3 Mag3(x, y, z);
	Vec4 Mag4(x, y, z, 0);
	std::cout << "[ANSWER] Normalized Vec =  (" << x << " , " << y<< " , " << z << ")" << std::endl;
	return Vec4(x, y, z , w);
}

float Vec4::Dot(Vec4 otherVec)			// Vec3& vecA, Vec3& vecB, float cosTheta
{
	return 0 ;
}





/// ****************************************************** Ray

/// Ray Class
void Ray::printStartPoint()
{
	printf("Point S (%f,%f,%f)\n", startX, startY, startZ);
}
void Ray::printDirection()
{
	printf("Point V (%f,%f,%f)\n", drX, drY, drZ);
}
void Ray::printQPoint()
{
	printf("Point Q (%f,%f,%f)\n", qX, qY, qZ);

}
void Ray::print()
{

	printf("(%f,%f,%f)\n", startX, startY, startZ);
	printf("(%f,%f,%f)\n", drX, drY, drZ);
	printf("(%f,%f,%f)\n", qX, qY, qZ);


}




// Default Set Vector(s) S , V , Q
Ray::Ray()
{
	startX = start.x;
	startY = start.y;
	startZ = start.z;
	
	qX = Q.x;
	qY = Q.y;
	qZ = Q.z;

	drX = direction.x;
	drY = direction.x;
	drZ = direction.x;
}

/// User Input Vec3 Constructor Set the Vector(s) S , V , Q
Ray::Ray(const Vec3& s, const Vec3& d , const Vec3& q)
{
	SetStart(s.x, s.y, s.z);
	SetDirection(d.x, d.y, d.z);
	SetQ(q.x, q.y, q.z);

}


Ray::Ray(Vec3 start_, Vec3 direction_)
{
	start.x = start_.x;
	start.y = start_.y;
	start.z = start_.z;
	
	direction.x = direction_.x;
	direction.y = direction_.y;
	direction.z = direction_.z;
	

}

Vec3 Ray::currentPosition(float t)
{
	// p(t) = (1 - S) + tV
	//start + direction * t;
	Vec3 dirV = start - direction;	dirV.print();

	return Vec3();
}

void Ray::setPlane(float x_, float y_, float z_, float w_)
{
	x_ = plane.x;
	y_ = plane.y;
	z_ = plane.z;
	w_ = plane.w;

}

/// Set start point	 ( S )
float Ray::SetStart(float x_, float y_, float z_)
{
     startX = x_;			// start.x
	 startY = y_;			// start.y
	 startZ = z_;			// start.z
	 Vec3 start(startX, startY, startZ);
	return startX, startY, startZ;
}

// get the start point
float Ray::getStart()
{
	//printf("[Debbuger] get start (%f,%f,%f)\n", startX, startY, startZ);
	return   start.x , start.y , start.z ;
	return startX, startY, startZ;
}


/// User float input set Direction  ( V ) 
// broken wont retrive values set always to one  !!
float Ray::SetDirection(float x, float y, float z)
{

	drX = x;   // direction.x
	drY = y;   // direction.y
	drZ = z;   // direction.z
	Vec3 direction(drX, drY, drZ);
	return drX, drY, drZ;
	//return direction;
}

// get the direction Pos vector  
float Ray::getDirection()
{
	//printf("[Debugger] GetDirection (%f,%f,%f) \n", drX, drY, drZ);
	Vec3 direction(drX, drY, drZ);
	return drX, drY, drZ;
}


/// User Vec3 input set Arbitrary ( Q )
float Ray::SetQ(Vec3& q)
{
	qX = q.x; //  Q.x
	qY = q.y; //  Q.y
	qZ = q.z; //  Q.z
	Vec3 Q(drX, drY, drZ);
	return qX, qY, qZ;
}

/// User float input set Arbitrary ( Q )
float Ray::SetQ(float qx, float qy, float qz)
{
	qX = qx; // Q.x
	qY = qy; // Q.y
	qZ = qz; // Q.z
	
	return qX, qY, qZ;
}

// Get the Q point 
float Ray::getQ()
{
	printf("Return Q Point (%f,%f,%f)\n", qX, qY, qZ);
	return qX, qY, qZ;
}



// Ray Distance
void Ray::rayDistanceVec(Ray ray, Vec3 Q)
{
	//ray.printStartPoint();		// print S	(start point)
	//ray.printDirection();			// print V
	//ray.printQPoint();			// print Q
	//Q.print();
	// Parametric EQ.			p(t) = S + tV
	// Distance Between Point.  d = ||Q - S|| ^ 2 - [(Q - S) . V]^2 / ||V||^2
	
	/// Get V , Find the Mag
	//ray.getDirection();
	float MagV = vec3.MagnitudeDistance(ray.drX , ray.drY , ray.drZ);
	// debug ray.printDirection();
	/// create a float mag print
	//printf("Magnitude of V =(%f) \n", MagV);
	
	/// Setting points S , V , Q into Vec3(s)
	Vec3 pointP = Vec3(ray.startX , startY , startZ);
	//pointP.print();
	Vec3 pointQ = Vec3(Q.x, Q.y, Q.z);
	//pointQ.print();

	/// Direction Vec3 , V
	Vec3 pointV = Vec3(ray.drX, ray.drY, ray.drZ);
	pointV.print();

	
	/// || Q - S || , Q point minus Starter Point	---> Original Q-S Vec3
	Vec3 QminuS = Vec3(pointQ - pointP);
	//QminuS.print();	// debug
	
	/// Take Vec3 Q-S and square it 
	Vec3 QminuSsq = Vec3(pow(QminuS.x, 2), pow(QminuS.y, 2), pow(QminuS.z, 2));
	//QminuSsq.print();  // debug

	/// Turn , save Vec3 Q-S ^ 2 in a float var
	float QminuSsqf = QminuSsq.x + QminuSsq.y + QminuSsq.z;

	/// Take original Q-S Vec3 , Find Dot Prod of V (direction)
	float QminuSDotV =  vec3.DotProd(QminuS , pointV);
	printf("Q-S . V = (%f) \n" , QminuSDotV);		// debug

	/// Square the Dot Product Q-S . V
	float QminuSDotVSquared = pow(QminuSDotV, 2);
	printf("Q-S . V ^ 2 = (%f)\n", QminuSDotVSquared);		// debug


	// Finalize equation
	float DistBetweenPointLine = sqrt(QminuSsqf - QminuSDotVSquared / MagV);
	printf("Distance Between Point & Line = (%f)\n", DistBetweenPointLine);

	// working...



}

// find point on a plane. .... uh oh , this one I was never good at I need to practice this one more ! 
void Ray::Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2)
{
	//Vec3 posVector = v0 - v1
}

Vec3 Ray::intersectionPoint(Ray ray)
{
	Vec3 v;
	return v;
}


Vec3 Ray::equationPlane(Vec3 Q, Vec3 normal, Vec3 Origin)
{
	// Q = P
// planeBody->normal = Origin
// planeShape = normal

// P - O
	Vec3 PO = Vec3(Q - Origin);
	float poDot = vec3.DotProd(PO, normal);
	printf("poDot Prod = %f\n", poDot); 


	Vec3 eqplane;
	return PO;
}
