#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int SumOfPairWiseHammingDistances(const vector<int> &A){
    int n = A.size();
    long long int answer=0;
    for(int i=0;i<32;i++){
        long long int count=0;
        for(int j=0;j<n;j++){
            if(A[j] & (1<<i))count++;
        }
        // Count has the number of ones in ith position of all the numbers given in vector
        // n-count is the number of zeros in similar case
        // For hamming distance each (1,0) pair adds to the answer
        // So to find each (1,0) pair do count*(n-count)
        // answer is multiplied by 2 to consider both (1,0) and (0,1) pairs.
        answer+=(count)*(n-count)*2;
        answer = answer % 1000000007;
    }
    return answer%1000000007;
}

int main(){
    vector<int> A = {2,4,5};
    cout<<SumOfPairWiseHammingDistances(A)<<endl;
    return 0;
}