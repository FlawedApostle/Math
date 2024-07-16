#include "rayLine.h"
#include "plane.h"

#include <string>

void plane::print()
{
 		printf("%s\n", hello);
        vector4Plane.print("plane V4 = ");
 }
void plane::print(const char* n)
{
    //hello = n;
    printf("[%s] \n",n);
}

plane::plane() : hello("hello from plane class !"),
x(0),
y(0),
z(0),
w(0)
{
    vector4Plane.setVector4xyzw(0, 0, 0, 1);
    //vector4Plane.setVector4x(0);
    //vector4Plane.setVector4y(0);
    //vector4Plane.setVector4z(0);
    //vector4Plane.setVector4w(1);
}

void plane::operator=(Vector4 p)
{
      vector4Plane.setVector4x(p.getVector4x());
      vector4Plane.setVector4y(p.getVector4y());
      vector4Plane.setVector4z(p.getVector4z());
      vector4Plane.setVector4w(p.getVector4w());
}

plane::~plane()
{
}
