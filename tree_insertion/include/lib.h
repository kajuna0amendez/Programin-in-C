#ifndef LIB_H
#define LIB_H
#include <stdbool.h>
#include <setjmp.h>

typedef struct stack_node stack_node;

typedef struct NODE NODE;

typedef struct {
    int *array;
    int left;
    int right;
} Segment;

struct stack_node{
    Segment *node;
    stack_node *next;
};

struct NODE{
    NODE *left;
    NODE *right;
    int value;
};

extern jmp_buf ENV;

stack_node* init_stack();

void push(int *array, int left, int right, stack_node **first_node);

stack_node* pop(stack_node **first_node);

void free_stack(stack_node **first_node);

void free_stack_node(stack_node **first_node);

bool isEmpty(stack_node **first_node);

void iterator_middle_init(int *array, int left, int right, stack_node **first_node);

void find_middle_iterator(int **element, stack_node **first_node);

NODE* create_node(int value);

void free_nodes(NODE **temp);

void insert_node(NODE **atree, int value);

void inorder_walk(NODE **atree);

#endif