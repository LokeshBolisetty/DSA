#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void RemoveNegativeIntegers(vector<int> &A){
    int n = 0;
    for(int i =0;i<A.size();i++){
        if(A[i]<=0){
            int temp = A[i];
            A[i] = A[n];
            A[n] = temp;
            n++;
        }
    }
    A.erase(A.begin(),A.begin()+n);
}
int SmallestPositiveMissingNumber(vector<int> &A){
    int n = A.size(),j=0;
    //Remove Negative Integers
    for(int i =0;i<n;i++){
        if(A[i]<=0){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            j++;
        }
    }
    A.erase(A.begin(),A.begin()+j);
    //Now calculate which number is missing
    //For an array of size n, the missing number has to be from 1 to n.
    //So use the given array only as a hash map. 
    //If the number at position x has -ve value, it means, x has been discovered already. 
    n=A.size();
    for(int i =0;i<n;i++){
        if(abs(A[i])-1<n && A[abs(A[i])-1]>0){
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        }
    }
    for(int i =0;i<n;i++){
        if(A[i]>0)return i+1;
    }   
    return n+1;
}
int main(){
    vector<int> A= {-1,2,3,0,-9,4,5};
    cout<<SmallestPositiveMissingNumber(A)<<endl;
    return 0;
}