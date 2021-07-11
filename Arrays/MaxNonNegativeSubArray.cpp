#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> MaximumNonNegativeSubArray(vector<int> A){
    long long start = 0,rstart=0,end=-1;
    long long max = LLONG_MIN;
    vector<int> v;
    long long sum=0;
    for(long long i =0;i<A.size();i++){
        if(A[i]<0){
            if(max<sum){
                max=sum;
                end = i;
                rstart=start;
            }
            if(i!=A.size()-1)start=i+1;
            sum=0;
        }else{
            sum+=A[i];
        }
    }
    if(sum>max){max = sum;
    rstart=start;
    end=A.size();}
    for(long long i =rstart;i<end;i++){
        v.push_back(A[i]);
    }
    return v;
}
int main(){
    vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v = MaximumNonNegativeSubArray(A);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}