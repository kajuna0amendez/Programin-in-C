#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "lib.h"

#define MAX_TESTS 10

typedef struct {
    const char *name;
    bool (*func_ptr)(stack_node**);
} test_func_entry;

test_func_entry test_funcs[MAX_TESTS];
int test_count = 0;

#define  REGISTER_TEST(func) \
    static void __attribute__((constructor)) register_##func(void) { \
        if (test_count < MAX_TESTS) { \
            test_funcs[test_count].name = #func; \
            test_funcs[test_count].func_ptr = func; \
            test_count++; \
        } \
    }

bool test_isempty(stack_node **first_node);

bool test_free(stack_node **first_node);

bool test_push(stack_node **first_node);

bool test_pop(stack_node **first_node);

void test_all();

#endif