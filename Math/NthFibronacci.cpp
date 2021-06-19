#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//There is a formula to calculate the nth fibronacchi number
// Fn = {[(sqrt(5)+1)/2]^n}/sqrt(5)
int FibronacchiFormula(int A){
    double f = (sqrt(5)+1)/2;
    f = pow(f,A);
    f/=sqrt(5);
    return round(f);
}

int FibronacchiRecursion(int A){
    if(A<3)return 1;
    else return FibronacchiRecursion(A-1)+FibronacchiRecursion(A-2);
}

int FibronacchiDP(int A){
    int fib[A+2];
    fib[0]=0;
    fib[1]=1,fib[2]=1;
    for(int i=3;i<A+1;i++){
        fib[i]=fib[i-1]%1000000007+fib[i-2]%1000000007;
    }
    int k= 3;
    return fib[A]%1000000007;
}

int FibronacciDPSpace(int n){
    int a=1,b=1,c=2;
    if(n==1 || n==2)return a;
    if(n==3) return c;
    for(int i=4;i<n+1;i++){
        a = b;
        b = c;
        c = a%1000000007 + b%1000000007;
    }
    return c%1000000007;
}

//For fibronacci Matrix
vector<long> mul(vector<long> m1, vector<long> m2){
    vector<long> ans(4);
    for(int i=0; i<=3; i++){
        m1[i] %= 1000000007;
        m2[i] %= 1000000007;
    }
    ans[0] = ( (m2[0]*m1[0])%1000000007 + (m2[2]*m1[1])%1000000007 )%1000000007;
    ans[1] = ( (m2[1]*m1[0])%1000000007 + (m2[3]*m1[1])%1000000007 )%1000000007;
    ans[2] = ( (m2[0]*m1[2])%1000000007 + (m2[2]*m1[3])%1000000007 )%1000000007; 
    ans[3] = ( (m2[1]*m1[2])%1000000007 + (m2[3]*m1[3])%1000000007 )%1000000007;
    return ans;
}
//For Fibronacci matrix
vector<long> power(vector<long> arr, int n){
    if(n==1) return arr;
    vector<long> temp  = power(arr, n/2);;
    if(n%2 == 0)  
        return mul(temp, temp);
    return mul( mul(temp, temp) , arr);
}

int FibronacciMatrix(int n) {
    if(n<=2) return 1;
    vector<long> arr = {1,1,1,0};
    arr = power(arr,n-1);
    return arr[0]%1000000007;
}

int main(){
    int N = 1000;
    cout<<FibronacchiDP(N)<<" ";
    cout<<endl;
    return 0;
}