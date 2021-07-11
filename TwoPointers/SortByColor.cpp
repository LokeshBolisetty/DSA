#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void SortByColor(vector<int> &A){
    int zero=0,one=0,two=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0)zero++;
        else if(A[i]==1)one++;
        else if(A[i]==2)two++;
    }int i=0;
    for(;i<zero;i++){
        A[i] = 0;
    }
    for(i;i<zero+one;i++){
        A[i] = 1;
    }
    for(;i<A.size();i++){
        A[i] = 2;
    }
}
int main(){
    vector<int> A =  {0,1,2,0,1,2};
    SortByColor(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }cout<<endl;
}