// Samuel Fearnley n01047308 Math Lib Summer 2024

#pragma once
#include <math.h>
#include <string>;
class Vec3 {
public:
	//float w;			// added 4D variable
	float x, y, z;
	float col1f = NULL;  
	float col2f = NULL; 
	float col3f = NULL; 
	float col4f = NULL;  
	float colf5 = NULL;
	float colf6 = NULL;

	int Col1minusCol2 = NULL;  
	int Col3minusCol4 = NULL;  
	int Col5minusCol6 = NULL;			// float
	
	// Print functions
	void print();
	void print(std::string note);
	Vec3& getVecQ();

	// Set
	void set(float x_, float y_, float z_);
	//void set(float x_, float y_, float z_ , float w_);
	
/// ****************************************************** Vec3
	
	// constructors
	Vec3();
	Vec3(float x, float y, float z);
	//Vec3(float x, float y, float z , float w_);
	Vec3(const Vec3& v);
	
	/// operators + , - , * , =
	const Vec3& operator + (const Vec3& v) const;
	Vec3& operator += (const Vec3& v);
	Vec3& operator = (const Vec3& v);
	// operators - 
	const Vec3& operator - (const Vec3& v) const;
	Vec3& operator -= (const Vec3& v);
	// operators *
	const Vec3& operator *(const Vec3& v);
	Vec3& operator *= (const Vec3& v);
	

	/// cross product
	Vec3& CrossProductVec(Vec3& A, Vec3& B, double sinTheta);
	float CrossProduct(const Vec3& v, const Vec3& b, float theta);			    // Vec3& 
	Vec3&  CrossProduct_2(Vec3& v, Vec3& b, double theta);						// Vec3& 
	Vec3& CrossProduct_3(Vec3& x, Vec3& y);				// double theta			// float
	
	/// magnitude
	float Mag(float x_, float y_, float z_);									// up for removal
	float Mag();																// up for removal
	// My functions
	float Magnitude(float x_, float y_, float z_);
	float MagnitudeDistance(float x_, float y_, float z_);						// Finding Distance Between Point & A Line
	Vec3& MagnitudeVec(Vec3& vecA);												// Final
	
	/// normalize
	Vec3 Normalize(float x, float y, float z);
	Vec3 Normalize();
	float Normalize_Vec4(float  x_, float y_, float z_);

	/// dot product
	float DotProduct(Vec3& a , Vec3& b , float angle_theta);					/// Dot Product Using Angle Theta, 
	float DotProductDistance(Vec3& a, Vec3& b);									/// Dot Product No angle , Long Hand Format
	
	// 4:20 Dot Prod
	float DotProd(Vec3& a, Vec3& b);
	
	
	Vec3& DotProduct_2(Vec3& a, Vec3& b, float angle_theta);
	Vec3& DotProduct_3(Vec3& a, Vec3& b, float angle_theta);
	Vec3& DotProductVec(Vec3& vecA, Vec3& vecB, float cosTheta);


	///////////////////////////Test Functions
	// Parametric
	// P(t) = S + tV
	// t >= 0
	//Vec3& t_infinity;
	//Vec3& v_direction;		// find mag for direction 
	float s_startingPoint;
	float parametric( Vec3 A, Vec3 B, float t);
	// Point TO line
	float  DistanceFromPointToLine(Vec3 Point_Start, Vec3 Point_End, Vec3 Q_arbitrary);
	/// Distance between A Point and a Line || Q - S|| returns a Vector
	Vec3 Q_Minus_S(const Vec3& V, const Vec3& v) const;
	/// Distance between A Point and a Line || Q - S|| ^ 2	 returns a float
	float Q_Minus_S_Squared(const Vec3& V, const Vec3& v) const;

};


/// ****************************************************** Vec4
class Vec4 : public Vec3{
public:
	float x, y, z, w;
	void set(float x_, float y_, float z_, float w_);
	// constructors
	Vec4(const Vec4& v);
	Vec4();
	Vec4(float x, float y, float z, float w);
	
	// Return the magnitude of the vector using Pythagoras’s theorem
	float Mag(float x, float  y, float z, float w);
	// Normalize the vector by dividing it by it’s magnitude
	// Return a normalized Vec4
	Vec4 Normalize(float x, float  y, float z, float w);

	// Dot this vector with the other one
	float Dot(Vec4 otherVec);


};



/// ****************************************************** Ray
class Ray
{
public:
	Vec3 vec3;		// class obj
	Vec4 vec4;		// class obj
	void printStartPoint();
	void printDirection();
	void printQPoint();
	void print();
	
	//float Sx, Sy, Sz, Dx, Dy, Dz;
	float startX, startY, startZ;
	float qX, qY, qZ;
	float drX, drY, drZ;
	float planex, planey, planez;
	Vec3 Q;					
	Vec3 start;				
	Vec3 direction;
	Vec4 plane;

	
	Ray(Vec3 start_, Vec3 direction_);
	Vec3 currentPosition(float t);
	
	void setPlane(float x_, float y_, float z_, float w_);
	void Set(float x_, float y_, float z_, float x, float y, float z);
	void Set(float x_, float y_, float z_);
	

	float SetStart(float x_, float y_, float z_);
	float getStart();
	
	float SetDirection(float x, float y, float z);
	float getDirection();

	

	float SetQ(Vec3& q_);
	float SetQ(float qx , float qy , float qz );
	float getQ();

	// default
	Ray();
	Ray(const Vec3& s, const Vec3& d);
	Ray(const Vec3& s, const Vec3& d , const Vec3& q);


	// Distance Between Point And Line
	void rayDistance(Ray ray, Ray Q , Ray S);		// Vec3 --> she wants a Vec3
	void rayDistanceVec(Ray ray, Vec3 Q);		// Vec3 --> she wants a Vec3

	// Define the plane using three points that are on the plane
	void Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2);
	// Find the intersection point of a ray passing through this plane
	Vec3 intersectionPoint(Ray ray);

	Vec3 equationPlane(Vec3 Q, Vec3 normal, Vec3 Origin);

};


//////////////////////////////////////////////////// Quaternion
