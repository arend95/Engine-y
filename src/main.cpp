#include "vec3.h"

int main(void) {
        
    // Test arithmetic
    vec3 v1(1.f, 2.5f, 4.f);
    vec3 v2(-6.f, 5.67f, 1.f);
    
    vec3 sum = vec3::Addition(v1, v2);
    vec3 ext = vec3::ExtProduct(v1, v2);
    
    float dot = vec3::DotProduct(v1, v2);

    std::cout << "Sum = [" << sum.xval << ", " << sum.yval << ", " << sum.zval << "]" << std::endl;
    std::cout << "Dot Product = " << dot << std::endl;
    std::cout << "Outer Product = [" << ext.xval << ", " << ext.yval << ", " << ext.zval << "]" << std::endl;
    
    // Test normalization
    v2.Normalize();
    std::cout << "Normalized v1 = " << v2.xval << " " << v2.yval << " " << v2.zval << std::endl;
    float dot2 = vec3::DotProduct(v2, v2);
    std::cout << "Dot Product normalized = " << dot2 << std::endl;
    
    // Test rotations
    vec3 v3(1.f, 0.f, 0.f);
    for(int i=0; i<360; i++) {
        v3.Rotatey(1.f);
        std::cout << v3.xval << std::endl;
    }
    return 0;
}
