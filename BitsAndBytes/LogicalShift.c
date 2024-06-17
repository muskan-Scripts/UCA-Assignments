/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/


#include<stdio.h>
#include<assert.h>

int logicalShift(int x, int n) {
    int mask= ~(1<<31>>(n-1));
    return (x>>n)& mask;
}
int main(){
    assert((int)141972530==logicalShift((unsigned int)2271560481U, 4));
    return 0;
}

// #include<stdio.h>
// #include<assert.h>


// int main(){
//     assert();
//     return 0;
// }

