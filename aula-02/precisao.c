#include <stdio.h>

int main() {
    float num1 = 0.0f;
    double num2 = 0.0;
    printf("DOUBLE\tFLOAT\n");
    for (int i = 1; i <= 100; i += 1) {
        num1 += 0.1f;
        num2 += 0.1;
        printf("%lf\t%f\n", num2, num1);
    }
    return 0;
}