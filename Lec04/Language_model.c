#include <stdio.h>

#include <iostream>

int main() {
    double n1, n2, n3, n4, n5;
    scanf("%lf%lf%lf%lf%lf", &n1, &n2, &n3, &n4, &n5);
    printf("%.15lf", n1 * n2 * n3 * n4 * n5);
    return 0;
}
