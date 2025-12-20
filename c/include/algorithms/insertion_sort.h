#pragma once
#include <stddef.h>

typedef int (*cmp_fn)(const void*, const void*);

int cmp_int(const void* a, const void* b);

void insertion_sort(
    void* base,
    size_t n,
    size_t elem_size,
    cmp_fn cmp
);