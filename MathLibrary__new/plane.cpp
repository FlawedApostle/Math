#include "rayLine.h"
#include "plane.h"

#include <string>

plane::plane() : hello("hello from plane class !"),
x(0),
y(0),
z(0),
w(0)
{   
    if (x == 0 || y == 0 || z == 0 || w == 0)
    {
        vector4Plane.setVector4xyzw(0, 0, 0, 1);
        printf("Default Plane Set\n");
    }
}
plane::~plane()
{
}


void plane::operator=(Vector4 p)
{
    vector4Plane.setVector4xyzw(p.getVector4());

    //vector4Plane.setVector4x(p.getVector4x());
    //vector4Plane.setVector4y(p.getVector4y());
    //vector4Plane.setVector4z(p.getVector4z());
    //vector4Plane.setVector4w(p.getVector4w());
}
