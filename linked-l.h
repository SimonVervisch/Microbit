#ifndef _LL_H
#define _LL_H_

#include "bullet.h"
#include "enemy.h"

#include <stdlib.h>

// used from https://www.learn-c.org/en/Linked_lists and slides Prof. E. Boix

typedef struct node_b {
    Bullet bullet;
    struct node_b * next;
} node_b;

typedef struct node_e {
    Enemy enemy;
    struct node_e * next;
} node_e;

uint8_t pop_node_e(node_e **head);
uint8_t remove_node_e_idx(node_e **head, uint8_t n);

#endif
