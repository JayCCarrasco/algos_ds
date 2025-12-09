#include <stdio.h>
#include <stdlib.h>
#include "ds/linked_list.h"

int main(void){
    LinkedList *list = createLinkedList();

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    *a = 10;
    *b = 20;

    pushBack(list, a);
    pushBack(list, b);

    printf("Size: %zu\n", getSize(list));

    int *x = popFront(list);
    printf("Pop: %d\n", *x);
    free(x);

    destroyLinkedList(list, free);
    
    return 0;
}
