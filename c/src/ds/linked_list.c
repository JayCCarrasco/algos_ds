//Libraries
#include "ds/linked_list.h"
#include <stdlib.h>

//create linked list
LinkedList* createLinkedList(void){
    LinkedList *new_ll = malloc(sizeof(LinkedList));
    if (!new_ll) return NULL;

    new_ll->head = NULL;
    new_ll->size = 0;

    return new_ll;
}


//destroy linked list
void destroyLinkedList(LinkedList *list, void (*free_fn)(void*)){
    if(!list) return;

    LinkedListNode* current = list->head;
    while(current){
        LinkedListNode* next = current->next;
        if (free_fn){
            free_fn(current->data);
        }
        free(current);
        current = next;
    }
    free(list);
}

int pushFront(LinkedList *list, void *data){
    if(!list) return -1;

    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    if(!newNode) return -1;

    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;
    list->size++;

    return 0;
}

int pushBack(LinkedList *list, void* data){
    if(!list) return -1;

    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    if(!newNode) return -1;

    newNode->data = data;
    newNode->next = NULL;

    if(!list->head){
        list->head = newNode;
    } else {
        LinkedListNode* tmpNode = list->head;
        while (tmpNode->next){
            tmpNode = tmpNode->next;
        }
        tmpNode->next = newNode;
    }
    list->size++;
    return 0;
}

void* popFront(LinkedList *list){
    if(!list || !list->head) return NULL;

    LinkedListNode *tmpNode = list->head;
    void *data = tmpNode->data;

    list->head = tmpNode->next;
    free(tmpNode);
    list->size--;

    return data;
}

size_t getSize(const LinkedList *list){
    return list ? list->size : 0;
}
