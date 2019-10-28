#include "vectors.h"
#include <cmath>
#include <cfloat>

#define CMP(x, y){fabsf((x)-(y)) <= FLT_EPSILON *fmaxf(1.0f, fmaxf(fabsf(x), fabsf(y)))}

/*vec2 operator+(const vec2& l, const vec2& r){
	return { l.x + r.x + l.y + r.y };
}*/