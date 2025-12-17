#include <stdlib.h>
#include <string.h>

#include "ds/vector.h"

#define INITIAL_CAPACITY 4

int vector_init(vector_t* v, size_t element_size){
    v->data = malloc(element_size * INITIAL_CAPACITY);
    if(!v->data) return -1;

    v->element_size = element_size;
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
    return 0;
}

int vector_push_back(vector_t* v, const void* element){
    if(v->size == v->capacity){
        size_t new_capacity = v->capacity * 2;
        void* new_data = realloc(v->data, v->element_size * new_capacity);
        if(!new_data) return -1;

        v->data = new_data;
        v->capacity = new_capacity;
    }

    void* dest = (char*)v->data + v->element_size * v->size;
    memcpy(dest, element, v->element_size);
    v->size++;
    return 0;
}

void* vector_get(vector_t* v, size_t index){
    if(index >= v->size) return NULL;
    return (char*)v->data + index * v->element_size;
}

void vector_pop_back(vector_t* v){
    if(v->size > 0){
        v->size--;
    }
}

void vector_destroy(vector_t* v){
    free(v->data);
    v->data = NULL;
}