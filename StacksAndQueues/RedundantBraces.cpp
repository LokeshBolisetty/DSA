#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int RedundantBraces(string A){
    stack<char> s;
    for(int i =0;i<A.size();i++){
        if(A[i]==')'){
            char c = s.top();
            if(c=='(')return 1;
            bool flag = false;
            while(c!='(' && !s.empty()){
                if(!isalnum(s.top()))flag = true;
                s.pop();
                c = s.top();
            }if(!flag)return 1;
            if(!s.empty())s.pop();
        }else{
            s.push(A[i]);
        }
    }
    return 0;
}
int main(){
    string s;
    cin>>s;
    if(RedundantBraces(s))cout<<"YES";
    else cout<<"NO";
    return 0;
}