#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void tailQS(stack_node **first_node){
    stack_node *temp;
    int *array;
    int left, right, N, i, pivot, swap_temp, key, it;
    double alpha;
    double accumulator;
    (void)alpha; // telling the compiler that is fine not using the variable
    (void)accumulator;
    if (!isEmpty(first_node)){
        // pop segment info for processing
        temp = pop(first_node);
        left = temp->node->left;
        right = temp->node->right;
        array = temp->node->array;
        // Get the random pivot to mantain
        // O(nlogn)
        if (left < right){
            accumulator = 0.0;
            N = right - left + 1;
            alpha = xorshift7();
            for (i = 0; i < N; i++){
                accumulator += 1.0/N;
                if (alpha <accumulator) break;
            }
            pivot = left + i;
            swap_temp = array[pivot];
            array[pivot] = array[right];
            array[right] = swap_temp;
            // Partition
            key = array[right];
            it = left - 1;
            for (i = left; i < right ; i++){
                if (array[i] <= key){
                    it++;
                    swap_temp = array[it];
                    array[it] = array[i];
                    array[i] = swap_temp;
                }
            }
            swap_temp = array[it + 1];
            array[it + 1] = array[right];
            array[right] = swap_temp;
            pivot = it + 1;
            // add stuff to the stack
            if (pivot == left && pivot != right){
                push(array, pivot + 1, right, first_node);
            } else if (pivot != left && pivot == right){
                push(array, left, pivot-1, first_node);
            } else {
                push(array, left, pivot-1, first_node);
                push(array, pivot + 1, right, first_node);
            }
        }
        tailQS(first_node);
    }
}



int* quicksort(int *array, int size){
    // dummy deed
    unsigned int seed[] = {1, 2, 3, 4, 5, 6, 7, 8};
    initxorshift7(seed, 0);
    // init stack
    stack_node *stack = init_stack();
    // push and call TailQS
    push(array, 0, size - 1, &stack);
    tailQS(&stack);
    return array;
}