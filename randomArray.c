#include "randomArray.h"

void generateRandomValues(int *vector, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        vector[i] = (rand() % (2 * size + 1)) - size;
        // O intervalo é de -size a +size
    }
}