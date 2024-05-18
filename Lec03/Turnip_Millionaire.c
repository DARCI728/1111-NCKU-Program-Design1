#include <stdio.h>

int main() {
    float d, h = 0;
    scanf("%f", &d);
    for (int i = 0; i < 5; i++) {
        h = (0.9 * d + 0.1 * h - 51);
        d = (-0.98 * h + 153);
        printf("%.1f ", d);
    }
    return 0;
}
