#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> AddOneToNumber(vector<int> &A){
    int i = A.size()-1;
    int carry = 1;
    for(;i>=0;i--){
        if(A[i]<9){
            if(A[i]+carry<=9){
                A[i]+=carry;
                break;
            }else{
                int t = carry;
                carry-=A[i];
                A[i] = (A[i]+carry)%10;
            }
        }else{
            A[i]=0;
        }
    }
    i = 0;
    while(A[i]==0 && i<A.size()){
        i++;
    }
    if(i==A.size()){
        A.insert(A.begin(),1);
        return A;
    }
    A.erase(A.begin(),A.begin()+i);
    return A;
}
int main(){
    vector<int> v = {9,9,9,9,9};
    AddOneToNumber(v);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}