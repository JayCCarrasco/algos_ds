#include <stdio.h>
#include <stdlib.h>
#include "ds/double_linked_list.h"

int main(void){
    dll_t *list = dll_create();

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    int *d = malloc(sizeof(int));

    *a = 10;
    *b = 20;
    *c = 30;
    *d = 40;

    dll_push_back(list, a);
    dll_push_back(list, b);

    dll_push_front(list, c);
    dll_push_front(list, d);

    printf("Size: %zu\n", dll_get_size(list));

    int *x = dll_pop_front(list);
    printf("Pop: %d\n", *x);
    free(x);

    int *y = dll_pop_back(list);
    printf("Pop: %d\n", *y);
    free(y);

    dll_destroy(list, free);

    return 0;
}