/*
/*  bitXor - x ^ y using only ~ and &
/* Example bitXor(4, 5) = 1
 
/* Max ops: 14
*/
#include<stdio.h>
#include<assert.h>
int bitXor (int x, int y) {
    return ~(~(~x&y) & ~(x & ~y));
}

int main(){
    assert(1==bitXor(4,5));
    return 0;
}

