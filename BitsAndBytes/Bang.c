#include<stdio.h>
#include<assert.h>

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/ 
int bang(int x) {
    int mask= ((x|(~x+1))>>31)&1;
    return mask ^ 1;
}
int main(){
    assert(bang(0)==1);
    return 0;
}