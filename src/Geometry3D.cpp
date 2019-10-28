#include "Geometry3D.h"
#include <cmath>
#include <cfloat>

float Length(const Line& line){
	return Magnitude(line.start - line.end);
}