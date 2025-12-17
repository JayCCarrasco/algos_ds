#pragma once
#include <stddef.h>

typedef struct vector {
    void* data;
    size_t element_size;
    size_t size;
    size_t capacity;
}vector_t;

int vector_init(vector_t* v, size_t element_size);
int vector_push_back(vector_t* v, const void* element);
void* vector_get(vector_t* v, size_t index);
void vector_pop_back(vector_t* v);
void vector_destroy(vector_t* v);