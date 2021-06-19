#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
int CountTotalSetBits(int A){
    #define MOD 1000000007
    if(A==0)return 0;
    long long int num=floor(log(A)/log(2)); //Number of bits in largest power of 2 less than n;
    long long int x = pow(2,num);
    x%=MOD;
    return ((x/2)*num+(A-x+1)+CountTotalSetBits(A-x))%MOD;
}
int main(){
    int A = 4;
    cout<<CountTotalSetBits(A)<<endl;
    return 0;
}