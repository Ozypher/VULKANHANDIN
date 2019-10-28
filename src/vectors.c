#include "vectors.h"
#include <cmath>
#include <cfloat>

vec2 operator+(const vec2& l, const vec2& r){
	return{ l.x + r.x + l.y + r.y };
}