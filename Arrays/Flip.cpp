#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
vector<int> Flip(string A){
    int n = A.size();
    int sum=0;
    vector<int> suffix(n);
    suffix[n-1]=int(A[n-1]);
    for(int i =n-2;i>=0;i--){
        suffix[i]= suffix[i+1] + int(A[i]);
    }int R=n-1,L=0;
    for(int i =n-1;i>=0;i--){
        int length=n-i;
        int flip=length-suffix[i];
        if(length==flip)R--;
        if(i<n-1 && suffix[i]>suffix[i+1])R--;
    }vector<int> prefix(n);
    prefix[0]=A[0];
    for(int i =1;i<n;i++){
        prefix[i] = prefix[i-1]+int(A[i]);
    }
    for(int i=0;i<n;i++){
        int length=i+1;
        int flip=length-prefix[i];
        if(length==prefix[i])L++;
        if(i>0)if(prefix[i]==prefix[i-1])L++;
    }
    return {L,R};
}*/
vector<int> Flip(string A){
    int count=0,maxCount=INT_MIN,l,r,ltemp=0,n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]=='1')count++;
    }if(count==n)return {};
    count=0;
    for(int i=0;i<n;i++){
        //We want max(zero-one) so increase count when u see 0 and decrease when u see 1
        //Max value of count is when you have max(zero-one)
        if(A[i]=='0')count++;
        else count--;
        if(count>maxCount){
            maxCount=count;
            l=ltemp;
            r=i;
        }
        if(count<0){
            count=0;
            ltemp=i+1;
        }
    }
    return {l+1,r+1};
}
int main(){
    string A = "111";
    vector<int> v = Flip(A);
    cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}