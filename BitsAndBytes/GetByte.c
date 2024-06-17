#include<stdio.h>
#include<assert.h>
/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6
*/
int getByte(int x, int n) {
    return ("0x%x", (x>>(n<<3))&255);
}

int main(){
    assert((int)86==getByte((int)305419896, 1));
    return 0;
}
