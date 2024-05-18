#include <math.h>
#include <stdio.h>

int main() {
    float x, y, BMI;
    scanf("%f %f", &x, &y);
    x = x / 100;
    BMI = y / (x * x);
    printf("%.6f", BMI);
}