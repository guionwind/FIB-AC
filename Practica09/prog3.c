#include <stdio.h>


int main() {
    long long x = 665857;
    long long y = 470832;
    long long z = x*x*x*x-4*(y*y*y*y)-4*(y*y);
    
    printf("El resultado es %lld\n", z);
    
}
