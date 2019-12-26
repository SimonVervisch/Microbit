#ifndef _LL_H
#define _LL_H_

#include "bullet.h"
#include "enemy.h"

// used from https://www.learn-c.org/en/Linked_lists and slides Prof. E. Boix

typedef struct node {
    Bullet bullet;
    struct node * next;
} node_b;

typedef struct node {
    Enemy enemy;
    struct node * next;
} node_e;
#endif
