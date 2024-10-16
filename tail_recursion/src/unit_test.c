#include "utest.h"
#include "lib.h"
#include "try_catch.h"
#include <stdio.h>
#include <math.h>

bool test_isempty(stack_node **first_node){
    int array[] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;

    if (!isEmpty(first_node)){
        longjmp(TRYENV, 1);
    }
    push(array, start, end, first_node);
    if (isEmpty(first_node)){
        longjmp(TRYENV, 1);
    }
    return true;
}
REGISTER_TEST_STACK(test_isempty);

bool test_free(stack_node **first_node){
    int array[] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;
    push(array, start, end, first_node);
    if (isEmpty(first_node)){
        longjmp(TRYENV, 1);
    }
    free_stack(first_node);
    if (!isEmpty(first_node)){
        longjmp(TRYENV, 1);
    }
    return true;
}
REGISTER_TEST_STACK(test_free);

bool test_push(stack_node **first_node){
    int array[] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;
    push(array, start, end, first_node);
    if (isEmpty(first_node)){
        longjmp(TRYENV, 1);
    }
    return true;
}
REGISTER_TEST_STACK(test_push);

bool test_pop(stack_node **first_node){
    int array[] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;
    push(array, start, end, first_node);
    stack_node *temp = pop(first_node);
    if (!(temp->node->left == start && temp->node->right == end)){
        longjmp(TRYENV, 1);
    }
    if (!isEmpty(first_node)){
        longjmp(TRYENV, 1);
    }
    return true;
}
REGISTER_TEST_STACK(test_pop);

void test_all_stack(void){
    stack_node *stack = init_stack();
    for (int i = 0; i < test_count_stack; i++){
        TRY {
            bool test1 = test_funcs_stack[i].func_ptr(&stack);
            if (test1 == true){
                printf("Correct test %s\n", test_funcs_stack[i].name);
            }
        } CATCH {
            printf("We have an error at %s\n", test_funcs_stack[i].name);
        }
        free_stack(&stack);
    }
}


bool test_random_mean(void){
    unsigned int seed[] = {1804784013U, 698059346U, 3920535147U,
                           708331212U, 84338163U, 2785678147U, 
                           1238376158U, 1557298846U};
    int value_test = 1000000;          
    double test = 0;
    double test_mean = 0.5;
    initxorshift7(seed, 0);

    for (int i = 0; i < value_test ; i++){
        test += xorshift7();
    }
    double mean =  test/value_test;
    printf("Difference %f\n", fabs(test_mean - mean));
    if (fabs(test_mean - mean) > 0.05){
        longjmp(TRYENV, 1);
    } 
    return true;
}
REGISTER_TEST_RANDOM(test_random_mean);


void test_all_random(void){
    for (volatile int i = 0; i < test_count_random; i++){
        TRY {
            bool test1 = test_funcs_random[i].func_ptr();
            if (test1 == true){
                printf("Correct test %s\n", test_funcs_random[i].name);
            }
        } CATCH {
            printf("We have an error at %s\n", test_funcs_random[i].name);
        }
    }
}

bool test_quicksort(void){
    int n = 10000000;
    int *array = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        array[i] = n - i;
    }
    int *test = quicksort(array, n);

    for (int i = 0; i < n; i++){
        if (test[i] != i + 1) longjmp(TRYENV, 1);
    }
    free(array);
    array = NULL;
    return true;
}
REGISTER_TEST_QUICKSORT(test_quicksort);

void test_all_quicksort(void){
    for (volatile int i = 0; i < test_count_quicksort; i++){
        TRY {
            bool test1 = test_funcs_quicksort[i].func_ptr();
            if (test1 == true){
                printf("Correct test %s\n", test_funcs_quicksort[i].name);
            }
        } CATCH {
            printf("We have an error at %s\n", test_funcs_quicksort[i].name);
        }
    }
}