#ifndef TRY_CATCH_H
#define TRY_CATCH_H

#include <setjmp.h>
#include <stdlib.h>

jmp_buf TRYENV;

// You can use different returns from longjump 
// and use exception = setenv(TRYENV) == 0 to catch
// exception up to you
#define TRY if(setjmp(TRYENV) == 0)
#define CATCH else

// ADD MORE AS YOU NEED

#endif