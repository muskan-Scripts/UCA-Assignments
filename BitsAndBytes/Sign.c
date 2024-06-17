/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/

#include<stdio.h>
#include<assert.h>
int sign(int x) {
   //TODO
   int signbit= x>>31;

    return signbit | !!x;
}

int main(){
    assert(1==sign(130));
    return 0;
}

