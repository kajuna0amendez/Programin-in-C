#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "lib.h"

#define MAX_TESTS 10

typedef struct {
    const char *name;
    bool (*func_ptr)(stack_node**);
} test_func_entry_stack;

typedef struct {
    const char *name;
    bool (*func_ptr)();
} test_func_entry_random;

typedef struct {
    const char *name;
    bool (*func_ptr)();
} test_func_entry_quicksort;

test_func_entry_stack test_funcs_stack[MAX_TESTS];
test_func_entry_random test_funcs_random[MAX_TESTS];
test_func_entry_quicksort test_funcs_quicksort[MAX_TESTS];

int test_count_stack = 0;
int test_count_random = 0;
int test_count_quicksort = 0;

#define  REGISTER_TEST_STACK(func) \
    static void __attribute__((constructor)) register_##func(void) { \
        if (test_count_stack < MAX_TESTS) { \
            test_funcs_stack[test_count_stack].name = #func; \
            test_funcs_stack[test_count_stack].func_ptr = func; \
            test_count_stack++; \
        } \
    }

#define  REGISTER_TEST_RANDOM(func) \
    static void __attribute__((constructor)) register_##func(void) { \
        if (test_count_random < MAX_TESTS) { \
            test_funcs_random[test_count_random].name = #func; \
            test_funcs_random[test_count_random].func_ptr = func; \
            test_count_random++; \
        } \
    }

#define  REGISTER_TEST_QUICKSORT(func) \
    static void __attribute__((constructor)) register_##func(void) { \
        if (test_count_quicksort < MAX_TESTS) { \
            test_funcs_quicksort[test_count_quicksort].name = #func; \
            test_funcs_quicksort[test_count_quicksort].func_ptr = func; \
            test_count_quicksort++; \
        } \
    }


bool test_isempty(stack_node **first_node);

bool test_free(stack_node **first_node);

bool test_push(stack_node **first_node);

bool test_pop(stack_node **first_node);

void test_all_stack(void);

bool test_random_mean(void);

void test_all_random(void);

bool test_quicksort(void);

void test_all_quicksort(void);

#endif