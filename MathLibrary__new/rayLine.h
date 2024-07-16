#pragma once
#include "Vector3.h"
class Vector3;
class Vector4;
class Quaternion;

class rayLine
{
	protected:
		Vector3 rayVector3;
		Vector3 dirStart;
		Vector3 dirEnd;

	public:
		void print(const char* notes);
		void print();
		rayLine();
		rayLine(Vector3 dirStart_, Vector3  dirEnd_);
		rayLine(float x , float y , float z , float i , float j , float k);
		~rayLine();

		Vector3& setdirStart(float x , float y , float z);
		Vector3& setdirStart(Vector3 dirStart_);
		Vector3& setdirEnd(float x, float y, float z);
		Vector3& setdirEnd(Vector3  dirEnd_);

		// L = P + t(p2-p1)
		Vector3& currentPosition(float t);




};

