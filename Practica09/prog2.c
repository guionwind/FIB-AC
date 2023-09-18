#include <stdio.h>


int main() {
    float x = 665857;
    float y = 470832;
    float z = x*x*x*x-4*(y*y*y*y)-4*(y*y);
    
    printf("El resultado es %f\n", z);
    
}
