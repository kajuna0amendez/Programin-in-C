#include "lib.h"
#include "utest.h"
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>


int main(){
    int array[] = {1,2,3,4,5};
    int lenght = sizeof(array)/sizeof(array[0]);
    int *element;
    test_all();
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