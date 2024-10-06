#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>


int main(){
    int array[] = {1,2,3,4,5};
    int lenght = sizeof(array)/sizeof(array[0]);
    int *element;
    printf("Test stack \n");
    stack_node *my_stack = init_stack();
    for (int i = 0; i < lenght ; i++){
        push(array, 0, i, &my_stack);
        if (my_stack  == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
        }
    }

    stack_node *temp = NULL;
    for (int i = 0; i < lenght ; i++){
        temp = pop(&my_stack);
        if (temp!=NULL){
            printf("left = %d right = %d\n", temp->node->left, temp->node->right);
            free_stack_node(&temp);
        }
    }
    free_stack(&my_stack);
    printf("End Test stack \n");

    printf("Test Iterator\n");
    stack_node *middle_stack = init_stack();

    iterator_middle_init(array, 0, lenght - 1, &middle_stack);

    if (setjmp(ENV) == 0){
        find_middle_iterator(&element, &middle_stack);
    }
    printf("output %d \n", *element);

    while(!isEmpty(&middle_stack)){
        find_middle_iterator(&element, &middle_stack);
    }

    free_stack(&middle_stack);

    printf("Test Binary Tree \n");

    stack_node *binary_stack = init_stack();
    NODE *atree = NULL;

    iterator_middle_init(array, 0, lenght - 1, &binary_stack);

    if (setjmp(ENV) == 0){
        find_middle_iterator(&element, &binary_stack);
    }
    insert_node(&atree, *element);

    while(!isEmpty(&binary_stack)){
        find_middle_iterator(&element, &binary_stack);
    }

    free_stack(&binary_stack);    

    printf("Inorder walk \n");
    inorder_walk(&atree);

    free_nodes(&atree);
}