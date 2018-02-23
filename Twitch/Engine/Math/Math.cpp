#include "Math.h"
#include <math.h>
namespace  Math
{
	double ConvertToRadians(double degrees) {
		return (degrees * PI) / 180;

	}


	double ConvertToDegrees(double radians) {
		return (radians * 180) / PI;
	}


	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot) {
		double radRot = ConvertToRadians(rot);
		double s = sin(radRot);
		double c = cos(radRot);

		point = point - pivot;
		float newX = (float)(point.x*c - point.y*s);
		float newY = (float)(point.x*s + point.y*c);



	}


}