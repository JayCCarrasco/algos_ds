//Libraries
#include "ds/double_linked_list.h"
#include <stdlib.h>

//create linked list
dll_t* dll_create(void){
    dll_t *new_ll = malloc(sizeof(dll_t));
    if (!new_ll) return NULL;

    new_ll->head = NULL;
    new_ll->tail = NULL;
    new_ll->size = 0;

    return new_ll;
}


//destroy linked list
void dll_destroy(dll_t *list, void (*free_fn)(void*)){
    if(!list) return;

    dll_node_t *current = list->head;
    while(current){
        dll_node_t *next = current->next;
        if (free_fn){
            free_fn(current->data);
        }
        free(current);
        current = next;
    }
    free(list);
}

int dll_push_front(dll_t *list, void *data){
    if(!list) return -1;

    dll_node_t* node = malloc(sizeof(dll_node_t));
    if(!node) return -1;

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if(list->head){
        list->head->prev = node;
        node->next = list->head;
    } else {
        list->tail = node;
    }

    list->head = node;
    list->size++;

    return 0;
}

int dll_push_back(dll_t *list, void* data){
    if(!list) return -1;

    dll_node_t* node = malloc(sizeof(dll_node_t));
    if(!node) return -1;

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if(list->tail){
        node->prev = list->tail;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
    return 0;
}

void* dll_pop_front(dll_t *list){
    if(!list || !list->head) return NULL;

    dll_node_t *tmp_node = list->head;
    void *data = tmp_node->data;

    if(list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = tmp_node->next;
    }

    free(tmp_node);
    list->size--;

    return data;
}

void* dll_pop_back(dll_t *list){
    if(!list || !list->tail) return NULL;

    dll_node_t *tmp_node = list->tail;
    void *data = tmp_node->data;

    if(list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = tmp_node->prev;
    }

    free(tmp_node);
    list->size--;

    return data;
}

size_t dll_get_size(const dll_t *list){
    return list ? list->size : 0;
}
