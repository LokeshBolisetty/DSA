#include <bits/stdc++.h>
using namespace std;
int Diffk(vector<int> &A,int B){
    int n = A.size();
    int i=0,j=1;
    while(i<n && j<n){
        if(A[j]-A[i]==B && i!=j)return 1;
        else if(A[j]-A[i]<B)j++;
        else i++;
    }
    return 0;
}
int main(){
    vector<int> A = {1,3,5};
    int B = 4;
    if(Diffk(A,B))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}