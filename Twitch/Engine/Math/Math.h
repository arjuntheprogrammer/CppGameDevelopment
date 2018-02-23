#ifndef TWITCH_MATH
#define TWITCH_MATH


#include "Vector3.h"
#define PI 3.14159

namespace Math
{
	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);

	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot);
}

#endif