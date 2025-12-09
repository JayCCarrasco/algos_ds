#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h> //size_t

typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
} LinkedListNode; 

typedef struct LinkedList {
    LinkedListNode* head;
    size_t size;
} LinkedList;

/*Creation and destruction*/
LinkedList* createLinkedList(void);
void destroyLinkedList(LinkedList *list, void (*free_fn)(void*));

/*Operations*/
int pushFront(LinkedList *list, void *data);
int pushBack(LinkedList *list, void *data);
void* popFront(LinkedList *list);

size_t getSize(const LinkedList *list);

#endif