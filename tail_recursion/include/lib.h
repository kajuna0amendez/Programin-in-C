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

extern unsigned int gen_state[8];

void initxorshift7(unsigned int *init, int sel);

double xorshift7(void);

void tailQS(stack_node **first_node);

int* quicksort(int *array, int size);

stack_node* init_stack();

void push(int *array, int left, int right, stack_node **first_node);

stack_node* pop(stack_node **first_node);

void free_stack(stack_node **first_node);

void free_stack_node(stack_node **first_node);

bool isEmpty(stack_node **first_node);



#endif