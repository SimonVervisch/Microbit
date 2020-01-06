#ifndef _LL_H
#define _LL_H_

#include "bullet.h"
#include "enemy.h"

#include <stdlib.h>

// used from https://www.learn-c.org/en/Linked_lists and slides Prof. E. Boix
// https://aticleworld.com/generic-linked-list-in-c/
// https://pseudomuto.com/2013/05/implementing-a-generic-linked-list-in-c/ || Deze laatste is zeer goed


typedef enum {
	ENEMY, BULLET
} TypeList;

void pop_node_t(node_t *head);
void remove_node_t_idx(node_t *head, uint8_t n);

// a common function used to free malloc'd objects
typedef void (*freeFunction)(void *);

typedef bool (*listIterator)(void *);

typedef struct _Node {
  void *data;
  struct _Node *next;
} Node;

typedef struct {
  int elementSize;
  Node *head;
  freeFunction freeFn;
} list;

void list_new(list *list, int elementSize, freeFunction freeFn);
void list_destroy(list *list);

void list_prepend(list *list, void *element);
void list_append(list *list, void *element);
int list_size(list *list);

void list_for_each(list *list, listIterator iterator);
// nog een map?
void list_head(list *list, void *element, bool removeFromList);
void list_tail(list *list, void *element);
void remove_first(list *list, TypeList typelist);

#endif

