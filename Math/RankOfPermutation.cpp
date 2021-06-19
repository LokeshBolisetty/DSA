#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/*
For each letter, calculate the position p in the set E, calculate s=p×(t−1)! 
and remove the letter from the set E (size t decreases). 
The sum of s is the rank of the permutation. 
Example:
For a string BAC 
B is in position 1 in ABC, sB=1×2!=2
A is in position 0 in AC, sA=0×1!=0
C is in position 0 in C, sC=0×0!=0
BAC is at permutation rank sB+sA+sC=2+0+0=2
*/
int fact(int N){
    if(N<=1)return 1;
    return (N*fact(N-1))%1000003;
}
int RankOfPermutation(string A){
    string sorted = A;
    int n=A.size();
    sort(sorted.begin(),sorted.end());
    long long int answer = 0;
    for(int i=0;i<n;i++){
        int idx = sorted.find(A[i]);
        answer += (idx*fact(n-i-1))%1000003;
        sorted.erase(sorted.begin()+idx,sorted.begin()+idx+1);
    }   
    return (answer+1)%1000003;
}
int main(){
    string s = "baa";
    cout<<RankOfPermutation(s)<<endl;
    return 0;
}