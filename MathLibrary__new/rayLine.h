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
		Vector3 dirFinal;

	public:
		//void print(const char* notes);
		//void print();
		//void printStart();
		//void printEnd();

		void print(const char* notes)
		{
			printf("[%s] \n", notes);
			//dirStart.print("dirStart=");
			//dirEnd.print("dirEnd=");
			dirFinal.print("dirFinal=");

		}
		void print()
		{
			dirStart.print("dirStart=");
			dirEnd.print("dirEnd=");
		}
			 
		void printStart()
		{
			dirStart.print("dirStart=");
		}
		void printStart(const char* notes)
		{
			printf("[%s] \n", notes);
			dirStart.print("dirStart=");
		}
		void printEnd()
		{
			dirEnd.print("dirEnd=");
		}
		void printEnd(const char* notes)
		{
			printf("[%s] \n", notes);
			dirEnd.print("dirEnd=");
		}
 
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

