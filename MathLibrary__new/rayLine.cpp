#include <iostream>
#include "rayLine.h"
#include <string>

rayLine::rayLine() :
	dirStart(0,0,0),
	dirEnd(0,0,0),
	dirFinal(0,0,0)
{
	//printf("hello new ray class\n");
}
// Constructors
rayLine::rayLine(Vector3 dirStart_, Vector3  dirEnd_)
{
	dirStart.setVector3x(dirStart_.getVector3x());
	dirStart.setVector3y(dirStart_.getVector3y());
	dirStart.setVector3z(dirStart_.getVector3z());

	dirEnd.setVector3x(dirEnd_.getVector3x());
	dirEnd.setVector3y(dirEnd_.getVector3y());
	dirEnd.setVector3z(dirEnd_.getVector3z());
}
rayLine::rayLine(float x, float y, float z, float i, float j, float k)
{
	dirStart.setVector3x(x);
	dirStart.setVector3y(y);
	dirStart.setVector3z(z);

	dirEnd.setVector3x(i);
	dirEnd.setVector3y(j);
	dirEnd.setVector3z(k);
}

rayLine::~rayLine()
{
}

// set start, end
Vector3& rayLine::setdirStart(float x , float y , float z)
{
	dirStart.setVector3x(x);
	dirStart.setVector3y(y);
	dirStart.setVector3z(z);
	return dirStart;
}
Vector3& rayLine::setdirStart(Vector3 dirStart_)
{
	dirStart.setVector3x(dirStart_.getVector3x());
	dirStart.setVector3y(dirStart_.getVector3y());
	dirStart.setVector3z(dirStart_.getVector3z());
	return dirStart;
}
Vector3& rayLine::setdirEnd(float x, float y, float z)
{
	dirEnd.setVector3x(x);
	dirEnd.setVector3y(y);
	dirEnd.setVector3z(z);
	return dirEnd;
}
Vector3& rayLine::setdirEnd(Vector3 dirEnd_)
{
	dirEnd.setVector3x(dirEnd_.getVector3x());
	dirEnd.setVector3y(dirEnd_.getVector3y());
	dirEnd.setVector3z(dirEnd_.getVector3z());
	return dirEnd;
}

Vector3& rayLine::currentPosition(float t)
{
	/// P = P + tV
	/// v = dirEnd - dirStart
	/// t = scalar
	/// P dirStart
	dirEnd.operator-(dirStart);
	Vector3 V;
	V.operator=(dirEnd);

	V = V * t;
	//Vector3 linePos
	//(
	//	dirStart + V.getVector3()
	//);
	dirFinal = (dirStart + V.getVector3());

	//linePos.print();
	return dirFinal;
}




