#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> FindPermutation(const string A,int B){
    vector<int> answer(B,-1);
    int t = 1;
    for(int i =0;i<B;i++){
        if(A[i]=='I'){
            answer[i] = t;
            t++;
        }
    }for(int i =B;i>=0;i--){
        if(answer[i]<0){
            answer[i] = t;
            t++;
        }
    }
    return answer;
}
int main(){
    string s = "DDDIDIDID";
    int n = 10;
    vector<int> v = FindPermutation(s,n);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}