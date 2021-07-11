#include<iostream>
#include <vector>
using namespace std;
//TTTTFFFF
int LastTrue(int A){
    if(A==0 || A==1)return A;
    long long int low = 1,high = A; //low and high are not initialised to 0,A/2
    //so that mid doesnt become 0 when we do low+high/2 and we dont get exception in 12
    long long int mid;
    while(low<high){
        mid = low+(high-low+1)/2;
        if(A/mid>=mid)low = mid; //Not A>=mid*mid due to overflow
        else high = mid-1;
    }
    return low;
}
int main(){
    int A = 4;
    cout<<LastTrue(A)<<endl;
    return 0;
}