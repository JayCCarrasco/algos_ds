#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <stddef.h>

typedef struct dll_node {
    void *data;
    struct dll_node *prev;
    struct dll_node *next;
} dll_node_t;

typedef struct dll {
    dll_node_t *head;
    dll_node_t *tail;
    size_t size;
} dll_t;

/*Creation and Destruction*/
dll_t* dll_create (void);
void dll_destroy(dll_t* list, void (*free_fn)(void*));

/*Operations*/
int dll_push_front(dll_t *list, void* data);
int dll_push_back(dll_t *list, void* data);
void* dll_pop_front(dll_t *list);
void* dll_pop_back(dll_t *list);

size_t dll_get_size(const dll_t *list);

#endif