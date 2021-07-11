#include<iostream>
using namespace std;
long long  power(long long A,long long B,long long C){
    if(A==0)return 0;
    if(B==0)return 1;
    if(A<0)A = (A%C+C)%C;
    if(B==1)return A%C;
    else if(B==0)return 1;
    else if(B%2==0){
        // long long ans = power(A,B/2,C);
        // ans*=ans;
        // ans%C;
        // return ans;
        return (power(A,B/2,C)*power(A,B/2,C))%C;
    }
    else {
        // long long ans = A*power(A,B-1,C);
        // ans%=C;
        // return ans;
        return (A*power(A,B-1,C))%C;
    }
}
int Mod(int A,int B,int C){
    if(A<0)A = (A%C+C)%C;
    return power(A,B,C);
}

signed main(){
    int A = 71045970;
    int B = 41535484;
    int C = 64735492;
    cout<<power(A,B,C);
    return 0;
}