#include<iostream>
#include<vector>
using namespace std;
int pickFromBothSidesWithoutPrefixArray(vector<int> &A, int B) {
    int firstSum = 0;
    for(int i=0;i<B;i++){
        firstSum+=A[i];
    }
    int currSum=firstSum;
    int maxSum = currSum;
    int left = B-1,right = A.size()-1;
    while(left>=0){
        currSum-=A[left--];
        currSum+=A[right--];
        if(currSum>maxSum)maxSum = currSum;
    }
    return maxSum;
}
int pickFromBothSidesWithPrefixArray(vector<int> &A,int B){
    //Create prefix array
    vector<int> prefix(A.size());
    prefix[0] = A[0];
    for(int i=1;i<A.size();i++){
        prefix[i] = prefix[i-1]+A[i];
    }
    //Create suffix array
    vector<int> suffix(A.size());
    suffix[0] = A[A.size()-1];
    for(int i=1;i<A.size();i++){
        suffix[i] = suffix[i-1]+A[A.size()-1-i];
    }
    //Find max sum
    int maxSum = 0;
    for(int i=0;i<B;i++){
        int currSum = prefix[i]+suffix[B-i-2];
        if(currSum>maxSum)maxSum = currSum;
    }
    return maxSum;
}
int main(){
    vector<int> A = {5, -2, 3 , 1, 2};
    int B = 3;
    cout<<pickFromBothSidesWithoutPrefixArray(A,B);
    return 0;
}