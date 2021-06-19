#include<iostream>
#include<unordered_map>
using namespace std;
int RomanToInteger(string A){
    unordered_map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int n = A.size(),answer=0;
    for(int i=0;i<n-1;i++){
        if(m[A[i]]<m[A[i+1]])answer-=m[A[i]];
        else answer+=m[A[i]];
    }
    answer+=m[A[n-1]];
    return answer;
}
int main(){
    string s = "MDCCCIV";//2019
    cout<<RomanToInteger(s)<<endl;
    return 0;
}