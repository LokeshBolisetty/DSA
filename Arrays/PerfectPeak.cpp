#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int PerfectPeak(vector<int> A){
    int n = A.size();
    vector<int> mn(n),mx(n);
    mx[0]=A[0]; int m=A[0];
    for(int i=1;i<n;i++){
        if(m<A[i])m=A[i];
        mx[i]=m;
    }
    m=A[n-1];
    mn[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        if(m>A[i])m=A[i];
        mn[i] = m;
    }
    for(int i =1;i<n-1;i++){
        if(A[i]>mx[i-1] && A[i] < mn[i+1])return 1;
    }
    return 0;
}
int main(){
    vector<int> A = { 1, 2, 3, 4, 5, 4, 3, 2, 3, 10 };
    cout<<PerfectPeak(A)<<endl;
    return 0;
}