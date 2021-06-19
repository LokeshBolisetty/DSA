#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MaxSumTriplet(vector<int> A){
    int n = A.size();
    vector<vector<int>> suffix(n);
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[j]>A[i]){
                if(suffix[i].size()<2){
                    suffix[i].push_back(A[j]);
                }else{
                    if(suffix[i][0]>suffix[i][1]){
                        int temp = suffix[i][1];
                        suffix[i][1] = suffix[i][0];
                        suffix[i][0] = temp;
                    }
                    if(suffix[i][0]<A[j]){
                        suffix[i][0]=A[j];
                    }
                }  
            }
        }
    }
    int sum=0,maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j =0;j<suffix[i].size();j++){
            if(sum==0)sum+=A[i];
            sum+=suffix[i][j];
        }
        if(sum>maxsum)maxsum=sum;
    }
    return maxsum;
}

int main(){
    vector<int> A = {3,2,1};
    cout<<MaxSumTriplet(A)<<endl;
    return 0;
}

/*
int MaxSumTriplet(vector<int> A){
    //This calculates the max of three contigous numbers in a vector.
    int n = A.size();
    if(n<3)return 0;
    int sum=A[0]+A[1]+A[2];
    int maxSum = sum;
    vector<int> prefix(n);
    prefix[0]= A[0];
    for(int i =1;i<n;i++){
        prefix[i] = prefix[i-1]+A[i];
    }
    for(int i =3;i<n;i++){
        sum = prefix[i]-prefix[i-3];
        if(sum>maxSum)maxSum = sum;
    }
    return maxSum;
}
*/