#include<stdio.h>
#include<assert.h>
/* 
/* Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
/* and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
/* Legal ops: ~ & ^ | << >>
/* as zero
*/
int invert (int x, int p, int n) {
    int mask= (~(~0<<n))<<p;
    return x^mask;
}

int main(){
    assert(invert((int)100010,2,4)==110);
    return 0;
}
