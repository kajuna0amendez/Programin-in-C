#include "lib.h"
#include <stdint.h>

unsigned int gen_state[8];

void initxorshift7(unsigned int *init, int sel){
    int j;
    if (sel == 0){
        unsigned int selection[] = {1804784013U, 698059346U, 3920535147U, 708331212U, 84338163U, 2785678147U, 1238376158U, 1557298846U};
        for (j=0; j<8; j++) gen_state[j] = selection[j];
    } else{
        for (j=0; j<8; j++) gen_state[j] = init[j];
    }
}

/* Final algorithmn from "On the Xorshift Random Number Generators" */
double xorshift7(void){
    // explanation for static int k
    // 1. Local scope: The variable k is only accessible within the function
    //     where it is declared. It cannot be accessed from outside that function.
    //
    // 2. Static storage duration: Despite having local scope, k retains its value
    //     between function calls. Unlike a regular local variable that is re-initialized 
    //    every time the function is called, a static variable is initialized only once,
    //     and it preserves its value across subsequent calls to the function.
    static int k = 0;
    unsigned int y, t;
    t = gen_state[(k+7) & 0x7U];
    t = t ^ (t<<13);
    y = t ^ (t<<9);
    t = gen_state[(k+4) & 0x7U];
    y = t ^ (t<<7);
    t = gen_state[(k+3) & 0x7U];
    y = t ^ (t>>3);
    t = gen_state[(k+1) & 0x7U];
    y = t ^ (t>>10);
    t = gen_state[k];
    t = t ^ (t>>7);
    y = t ^ (t<<24);
    gen_state[k] = y;
    k = (k+1) & 0x7U;
    return ((double) y * 2.32830643653869628906e-10 );
}