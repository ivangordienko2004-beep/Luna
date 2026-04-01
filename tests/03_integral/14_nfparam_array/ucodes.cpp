#include <cstdio>
#include "ucenv.h"

extern "C" {

void c_init(OutputDF &df, int val) {
    df.setValue(val);
}

void c_iprint(int val) {
    printf("%d\n", val);
}

void c_iaprint(int* array) {
    printf("%d / %d\n", sizeof(array), sizeof(int));
    printf("[ ");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        printf("%d ", array + i);
    }
    printf("]\n");
}

}
