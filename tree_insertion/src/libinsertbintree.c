#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

NODE* create_node(int value) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


void free_nodes(NODE **temp){
    if (*temp == NULL){
        return;
    }
    free_nodes(&(*temp)->left);
    free_nodes(&(*temp)->right);
    free(*temp);
    *temp = NULL;
}

void insert_node(NODE **atree, int value){
    if (*atree == NULL){
        *atree = create_node(value);
    } else {
        NODE *prev = NULL;
        NODE *next = *atree;
        while (next != NULL){
            prev = next;
            if (next->value < value){
                next = next->right;
            } else {
                next = next->left;
            } 
        }
        if (value < prev->value){
            prev->left = create_node(value);
        }
        else {
            prev->right = create_node(value);
        }
    }
}

void inorder_walk(NODE **atree){
    if (*atree != NULL){
        inorder_walk(&(*atree)->left);
        printf("%d \n", (*atree)->value);
        inorder_walk(&(*atree)->right);
    }
}

