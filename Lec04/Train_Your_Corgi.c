typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

#include <stdio.h>
#include <string.h>

int main() {
    Strength strength = INIT_STRENGTH;
    Obedience obedience = INIT_OBEDIENCE;
    int count = 0;
    char training[100];
    scanf("%s", training);
    for (int i = 0; i < strlen(training); i++) {
        if (training[i] == 'e') {
            strength += STRENGTH_EAT;
            obedience -= OBEDIENCE_EAT;
        } else if (training[i] == 't') {
            strength -= STRENGTH_TRAIN;
            obedience += OBEDIENCE_TRAIN;
        }
        if (obedience >= LEARN_OBEDIENCE && strength <= LEARN_STRENGTH) {
            obedience = INIT_OBEDIENCE;
            count += 1;
        }
    }
    if (count >= 5) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}
