#include "lib.h"
#include "utest.h"
#include "try_catch.h"
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>


int main(){
    test_all_stack();
    test_all_random();
    test_all_quicksort();
    return 0;
}