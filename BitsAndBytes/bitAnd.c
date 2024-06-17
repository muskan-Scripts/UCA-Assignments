/*
/*  bitAnd - x & y using only ~ and |
/* Example bitAn/ Legal ops:  ~ |  d(6, 5) = 4
*
/*Max ops: 8
*/
#include<stdio.h>
#include<assert.h>
int bitAnd (int x, int y) {

     return ~(~x | ~y);
}

int main(){
    assert(4==bitAnd(6,5));
    return 0;
}

