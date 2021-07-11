#include <bits/stdc++.h>
using namespace std;
/*
Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.

Problem Constraints

    1 <= N <= 10^5
    -10^3 <= A[i] <= 10^3
    -10^5 <= B <= 10^5

Input 1
 A = [5, 10, 3, 2, 50, 80]
 B = 78
Output 1
1

Input 2
A = [-10,20]
B = 30
Output 2
1
*/
int PairWithGivenDifference(vector<int> A,int B){
    int n = A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++){
        int a = A[i]-B;
        if(a==A[i]){ 
        // If the number required is the same as current number
        // You need to check if there is a copy of that number again. 
        // Since this is a sorted matrix, if there is a copy, it has to be on the immediate right
        // or immediate left. So we are checking for the same. 
            if(i>0){
                if(A[i]==A[i-1])return 1;                
            }
            if(i<n-1){
                if(A[i]==A[i+1])return 1;
            }
        }
        // If the number required is not the same, then we perform a binary search to 
        // see if the number we are looking for is there in the array
        // if it is there we return true, else we continue to search if other elements form
        // the required pair. 
        else if(binary_search(A.begin(),A.end(),a)){
            return 1;
        }
    }
    return 0;
}
int main(){
    vector<int> v = {20,500,1000,200};
    if(PairWithGivenDifference(v,0)){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}