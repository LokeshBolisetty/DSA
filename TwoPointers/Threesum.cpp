#include<bits/stdc++.h>
using namespace std;
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution
*/
int NearsetThreeSum(vector<int> &A,int B){
    if(A.size()<3)return 0;
    sort(A.begin(),A.end());
    int n = A.size();
    int result=A[0]+A[1]+A[n-1];
    for(int i=0;i<n-2;i++){
        int low = i+1;
        int high = n-1;
        while(low<high){
            int sum = A[i] + A[low]+A[high];
            if(abs(sum-B)<abs(result-B))result = sum;
            if(sum==B)return B;
            if(sum>B)high--;
            else if(sum<B)low++;
        }
    }
    return result;
}
int main(){
    vector<int> A = {-1,2,1,-4};
    int B= 1;
    cout<<"Nearest Sum to the target is "<<NearsetThreeSum(A,B)<<endl;
    return 0;
}