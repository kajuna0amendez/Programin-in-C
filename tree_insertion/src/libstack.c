#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

stack_node* init_stack(){
    stack_node *first_node = NULL;
    return first_node;
}

void push(int *array, int left, int right, stack_node **first_node) {
    stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
    new_node->node = (Segment *)malloc(sizeof(Segment));
    new_node->node->array = array;
    new_node->node->left = left;
    new_node->node->right = right;
    new_node->next = NULL;
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    if (first_node == NULL){
        *first_node = new_node;
    }else {
        new_node->next = *first_node;
        *first_node = new_node;
    }
}

stack_node* pop(stack_node **first_node){
    stack_node *new_node = NULL;
    if (*first_node!=NULL){
        new_node = *first_node;
        *first_node = (*first_node)->next;
        new_node->next = NULL;
    }
    return new_node;
}

void free_stack(stack_node **first_node){
    while (*first_node != NULL){
        Segment *_tseg = (*first_node)->node;
        if (_tseg != NULL){
            free(_tseg);
            _tseg = NULL;
        }
        stack_node *temp = *first_node;
        *first_node = (*first_node)->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
    }
}


void free_stack_node(stack_node **first_node){
    Segment *_tseg = (*first_node)->node;
    if (_tseg != NULL){
        free(_tseg);
        _tseg = NULL;
    }
    stack_node *temp = *first_node;
    *first_node = (*first_node)->next;
    temp->next = NULL;
    free(temp);
    temp = NULL;
}

bool isEmpty(stack_node **first_node){
    if (*first_node != NULL){
        return false;
    }
    return true;
}

