#include "lib.h"
#include <setjmp.h>
#include <stdio.h>

jmp_buf ENV; 

void iterator_middle_init(int *array, int left, int right, stack_node **first_node) {
    push(array, left, right, first_node);
}


void find_middle_iterator(int **element, stack_node **first_node){
    while (!isEmpty(first_node)){
        stack_node *temp = pop(first_node);
        int *array = temp->node->array;
        int left = temp->node->left;
        int right = temp->node->right;
        if (left == right) {
                *element = &array[left];
        } else {
            int middle = left + (right - left) / 2;
            *element = &array[middle];
            if (left < right && left != middle && right != middle){
                push(array, middle + 1, right, first_node);
                push(array, left, middle - 1, first_node);
            }  if (left < right && left == middle && right != middle){
                push(array, middle + 1, right, first_node);
            } 
        }
        longjmp(ENV, 1); 
    }
}