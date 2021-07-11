#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//From a non-changable array, find out if there is any number that appears more than N/3 times using O(1) space and in O(n) time
int Nby3(const vector<int> &A){
    //The below approach uses Moore's Voting algorithm https://www.geeksforgeeks.org/majority-element/
    int n = A.size();
    int count1=0,count2=0,first=INT_MAX,second=INT_MAX;
    for(int i =1;i<n;i++){
        if(A[i]==first){
            count1++;
        }else if(A[i]==second){
            count2++;
        }else if(count1==0){
            count1++;
            first=A[i];
        }else if(count2==0){
            count2++;
            second=A[i];
        }else{
            count1--;
            count2--;
        }
    }
    count1=0,count2=0;
    for(int i =0;i<n;i++){
        if(A[i]==first)count1++;
        else if(A[i]==second)count2++;
    }
    if(count1>n/3)return first;
    if(count2>n/3)return second;
    return -1;
}
int main(){
    vector<int> v = {1,1,1,2,3,5,7};
    cout<<Nby3(v)<<endl;
    return 0;
}