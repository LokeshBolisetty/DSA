#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> MergeTwoSortedArrays(vector<int> A,vector<int> B){
    int a = A.size(),b = B.size();
    int ai=0,bi=0;
    A.resize(a+b);//This is important. You can use v.insert() also but each insertion then takes O(n)
    //Resizing first gives us the ability to use indices and hence making it O(1).
    int i=a-1,j=b-1;
    while(i>=0 && j>=0){
        if(A[i]<B[j]){
            A[i+j+1]=B[j];
            j--;
        }else{
            A[i+j+1] = A[i];
            i--;
        }
    }
    while(j>=0){
        A[j] = B[j]; //Here we put B[j] in A[j] itself.(Only then will 0th index be filled obv) 
        j--;
    }
    return A;
}
int main(){
    vector<int> A = {-4,3};
                 //  -4 3 _ _ 
    vector<int> B = {-2,-2};
    vector<int> answer = MergeTwoSortedArrays(A,B);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }cout<<endl;
    return 0;
}