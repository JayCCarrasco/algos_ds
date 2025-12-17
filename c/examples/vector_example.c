#include <stdio.h>
#include "ds/vector.h"

int main() {
    vector_t v;
    vector_init(&v, sizeof(int));

    for (int i = 0; i < 10; i++) {
        vector_push_back(&v, &i);
    }

    for (size_t i = 0; i < v.size; i++) {
        int* p = vector_get(&v, i);
        printf("%d ", *p);
    }

    printf("\n");
    vector_destroy(&v);
    return 0;
}
