#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ReverseInteger(int A){
    long long int B=0; // long long to take care of overflow
    bool flag = false;
    if(A<0){
        A*=-1;
        flag = true;
    }
    while(A>0){
        B = 10*B + A%10; //reversing the integer
        A/=10;
    }
    if(flag)B*=-1;
    if(B<=INT_MAX && B>=INT_MIN)return B; // If the integer given is out of bounds, we should return zero.
    return 0;

}
int main(){
    int A = -1146467285;
    cout<<ReverseInteger(A)<<endl;
    return 0;
}