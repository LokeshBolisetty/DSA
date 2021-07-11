#include<iostream>
using namespace std;
int TrailingZeros(int A){
    int count=0;
    while(A>0){
        if(A%2==0)count++;
        else break;
        A/=2;
    }
    return count;
}
int main(){
    int A = 18;
    cout<<TrailingZeros(A)<<endl;
    return 0;
}