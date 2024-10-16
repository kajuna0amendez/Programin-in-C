#include "utest.h"
#include "lib.h"
#include "try_catch.h"
#include <stdio.h>

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
REGISTER_TEST(test_isempty);

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
REGISTER_TEST(test_free);

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
REGISTER_TEST(test_push);

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
REGISTER_TEST(test_pop);

void test_all(){
    stack_node *stack = init_stack();
    for (int i = 0; i < test_count; i++){
        TRY {
            bool test1 = test_funcs[i].func_ptr(&stack);
            if (test1 == true){
                printf("Correct test %s\n", test_funcs[i].name);
            }
        } CATCH {
            printf("We have an error at %s\n", test_funcs[i].name);
        }
        free_stack(&stack);
    }
}