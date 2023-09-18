#include <stdio.h>


int main() {
    double x = 665857;
    double y = 470832;
    double z = x*x*x*x-4*(y*y*y*y)-4*(y*y);
    
    printf("El resultado es %lf\n", z);
    
}
