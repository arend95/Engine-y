#include <iostream>
#include <cmath>

#ifndef vec3_H
#define vec3_H

#define PI 3.14159265

class vec3 {
public:
    // Constructors
    vec3();
    vec3(float x, float y, float z);
    
    // vec3 elements
    float xval;
    float yval;
    float zval;
    
    
    // Binary arithmetic - call through scope operator
    static vec3 Addition(vec3 &v1, vec3 &v2);
    static float DotProduct(vec3 &v1, vec3 &v2);
    static vec3 ExtProduct(vec3 &v1, vec3 &v2);
    
    // Auxiliary functions - call as object method
    void Normalize();
    
    // Rotators - call as object method
    void Rotatex(float angle);
    void Rotatey(float angle);
    void Rotatez(float angle);
    
    // TODO: add reflection operators

};

#endif
    
