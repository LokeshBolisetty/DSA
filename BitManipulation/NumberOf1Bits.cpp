#include<bits/stdc++.h>
using namespace std;
int NumberOf1Bits(int A){
    int count=0;
    while(A){
        int n = A&1;
        count+=n;
        A>>=1;
    }
    return count;
}
int Brian_Kernighan(int x){
    //This is editorial solution
    /*
    Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
for example : 
10 in binary is 00001010 
9 in binary is 00001001 
8 in binary is 00001000 
7 in binary is 00000111 
So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count. 
The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer. 
    */
    unsigned int total_ones = 0;
    while (x != 0) {
        x = x & (x-1);
        total_ones++;
    }
    return total_ones;
}
int main(){
    int x = 11;
    cout<<NumberOf1Bits(x)<<endl;
    return 0;
}