#include "algorithms/insertion_sort.h"
#include <string.h>
#include <stdlib.h>

int cmp_int(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return x - y;
}

void insertion_sort(void* base, size_t n, size_t elem_size, int(*cmp)(const void*, const void*)){
    char* arr = (char*) base;   //arr points to first byte in base

    for(size_t i = 1; i < n; i++){
        char temp[elem_size];
        memcpy(temp, arr + i * elem_size, elem_size);

        size_t j = i;
        while (j > 0 && cmp(arr + (j - 1) * elem_size, temp) > 0){
            memmove(arr + j * elem_size, arr + (j - 1) * elem_size, elem_size);
            j--;
        }

        memcpy(arr + j * elem_size, temp, elem_size);
    }
}



