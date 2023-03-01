/**
 * @file linklist.h
 * @author jay
 * @version 0.1
 * @date 2023-03-01
 */

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *NODEp;

void display(NODEp);
NODEp createList(int *, int);
void insertNode(NODEp, int);
NODEp insertFirst(NODEp, int);
NODEp deleteNode(NODEp, NODEp);
NODEp searchNode(NODEp, int);
void freeList(NODEp);
