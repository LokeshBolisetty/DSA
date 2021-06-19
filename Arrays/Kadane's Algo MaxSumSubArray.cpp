#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int MaxSumSubArray(vector<int> A){
    int maxCurrent = A[0], maxGlobal=A[0];
    for(int i =1;i<A.size();i++){
        maxCurrent = max(A[i],maxCurrent+A[i]);
        if(maxCurrent>maxGlobal)maxGlobal = maxCurrent;
    }
    return maxGlobal;
}
int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<MaxSumSubArray(v)<<endl;
    return 0;
}