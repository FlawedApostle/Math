#include <iostream>
#include "Vector4.h"
//#include "Vector3.h"
//#include "Quat.h"

Vector4& Vector4::operator+(Vector4& v)
{
	float i = x + v.x;
	float j = y + v.y;
	float k = z + v.z;
	float W = w + v.w;
	//Vector4 add(v.x + x, v.y + y, v.z + z, v.w + w);
	x = i;
	y = j;
	z = k;
	w = W;
	Vector4 add (x, y, z, w);
	add.operator=(add);
	//add.print("Vector4 add");5
	return add;
}
Vector4& Vector4::operator=(Vector4& v)
{
	float i = x = v.x;
	float j = y = v.y;
	float k = z = v.z;
	float W = w = v.w;

	x = i;
	y = j;
	k = z;
	W = w;
	Vector4 ijk(x, y, z, w);
	//ijk.print("Vector4 =");
	return ijk;
}
Vector4& Vector4::operator-(Vector4& v)
{
	float i, j, k , W;
	i = x = x - v.x;
	j = y = y - v.y;
	k = z = z - v.z;
	W = w = w - v.w;
	Vector4 minus(x, y, z, w);
	return  minus;
}
Vector4& Vector4::operator*(Vector4& v)
{
	float i, j, k, W;
	i = x = x * v.x;
	j = y = y * v.y;
	k = z = z * v.z;
	W = w = w * v.w;
	Vector4 mult(x, y, z, w);
	return mult;
}
// scalar *
Vector4& Vector4::operator*(float s)
{
	x * s;
	y * s;
	z * s;
	w * s;
	Vector4 multS(x, y, z, w);
	return multS;
}
// scalar /
Vector4& Vector4::operator/(Vector4& v)
{
	float i, j, k, W;
	i = x = x / v.x;
	j = y = y / v.y;
	k = z = z / v.z;
	W = w = w / v.w;
	Vector4 div(x, y, z, w);
	return div;

}
Vector4& Vector4::operator/(float s)
{
	x / s;
	y / s;
	z / s;
	w / s;
	Vector4 divS(x, y, z, w);
	return divS;
}

float const Vector4::magVector4(Vector4& v) const
{
	float mag;
	mag = sqrt((pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2)));
	//printf("Vector4 mag = %f\n", mag);
	return mag;
}

Vector4& const Vector4::normVector4(Vector4& v) const
{
	Vector4 norm;
	float i = x , j = y, k = z;


	//	i			j			  k
	//	v.x			v.y			  v.z
	//  x			y			    z
	// (v.y*z) + (v.z*y)i +
	// (v.x*y) + (v.y*x)j +
	// (v.x*y) + (v.y*x)k

	//dot = (v.y * z) + (v.z * y) + (v.x * y) + (v.y * x) + (v.x * y) + (v.y * x);
	//printf("dot = %f\n", dot);
	return norm;
}

float Vector4::dotVector4(Vector4& v, Vector4& b)
{
	float dot;
	dot = (v.x * b.x) + (v.y * b.y) + (v.z * b.z);
	//printf("Vector4 dot=%f\n", dot);
	return dot;
}

Vector4& Vector4::crossVector4(Vector4& v, Vector4& b)
{

	/*					correct formula tested July 2024
	//			i			j			  k			w
	//			v.x			v.y			  v.z		v.w
	//			b.x			b.y			  b.z		b.w

	//					 // Determinant
	//					(v.y * b.z) - (v.z * b.y)i -
	//					(b.x * v.z) - (v.x * b.z)j +
	//					(v.x * b.y) - (v.y * b.x)k
*/
	float i,j,k,W;

	W = w;	// leave w untouched
	i = (v.y * b.z) - (v.z * b.y);
	j = (b.x * v.z) - (v.x * b.z);
	k = (v.x * b.y) - (v.y * b.x);

	x = i;
	y = j;
	z = k;
	Vector4 cross(x,y,z,w);
	//cross.print("cross");
	return cross;
}
