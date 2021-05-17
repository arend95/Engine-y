#include "vec3.h"

// CONSTRUCTORS //
vec3::vec3() {
    this->xval = 0;
    this->yval = 0;
    this->zval = 0;
}

vec3::vec3(float x, float y, float z) {
    this->xval = x;
    this->yval = y;
    this->zval = z;
}

// BINARY OPERATORS //
vec3 vec3::Addition(vec3 &v1, vec3 &v2) {
    vec3 Out;
    
    Out.xval = v1.xval + v2.xval;
    Out.yval = v1.yval + v2.yval;
    Out.zval = v1.zval + v2.zval;
    
    return Out;
}

float vec3::DotProduct(vec3 &v1, vec3 &v2) {
    float Out;
    
    Out = v1.xval*v2.xval + v1.yval*v2.yval + v1.zval*v2.zval;
    
    return Out;
}

vec3 vec3::ExtProduct(vec3 &v1, vec3 &v2) {
    vec3 Out;
    
    Out.xval = v1.yval*v2.zval - v1.zval*v2.yval;
    Out.yval = v1.zval*v2.xval - v1.xval*v2.zval;
    Out.zval = v1.xval*v2.yval - v1.yval*v2.xval;
    
    return Out;
}

// AUXILIARY FUNCTIONS //
void vec3::Normalize() {
    // Taken from QUAKE III ARENA source code
    float number = this->xval*this->xval + this->yval*this->yval + this->zval*this->zval;
    
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    
    this->xval *= y;
    this->yval *= y;
    this->zval *= y;
}

// ROTATORS //
void vec3::Rotatex(float angle) {
    float y, z;

    y = std::cos(PI*angle/180)*this->yval - std::sin(PI*angle/180)*this->zval;
    z = std::sin(PI*angle/180)*this->yval + std::cos(PI*angle/180)*this->zval;

    this->yval = y;
    this->zval = z;
}

void vec3::Rotatey(float angle) {
    float x, z;
    
    x = std::cos(PI*angle/180)*this->xval + std::sin(PI*angle/180)*this->zval;
    z = -std::sin(PI*angle/180)*this->xval + std::cos(PI*angle/180)*this->zval;
    
    this->xval = x;
    this->zval = z;
}

void vec3::Rotatez(float angle) {
    float x, y;
    
    x = std::cos(PI*angle/180)*this->xval - std::sin(PI*angle/180)*this->yval;
    y = std::sin(PI*angle/180)*this->xval + std::cos(PI*angle/180)*this->yval;
    
    this->xval = x;
    this->yval = y;
}
