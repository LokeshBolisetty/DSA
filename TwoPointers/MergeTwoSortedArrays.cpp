#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> MergeTwoSortedArrays(vector<int> A,vector<int> B){
    vector<int> answer;
    int a = A.size(),b = B.size();
    int ai=0,bi=0;
    while(answer.size()<a+b){
        while(ai<a && bi<b && A[ai]<=B[bi]){
            answer.push_back(A[ai]);
            ai++;
        }
        while(ai<a && bi<b && A[ai]>B[bi]){
            answer.push_back(B[bi]);
            bi++;
        }
        if(ai==a){
            while(bi<b){
                answer.push_back(B[bi]);
                bi++;
            }
        }else if(bi==b){
            while(ai<a){
                answer.push_back(A[ai]);
                ai++;
            }
        }
    }
    return answer;
}
int main(){
    vector<int> A = {1,4,7,10,12};
    vector<int> B = {0,2,3,19,24,32,78,90};
    vector<int> answer = MergeTwoSortedArrays(A,B);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }cout<<endl;
    return 0;
}