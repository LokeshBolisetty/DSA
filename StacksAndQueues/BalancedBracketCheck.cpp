#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool balanceCheck(string str){
    stack<char> s;
    for(int i =0;i<str.size();i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            s.push(str[i]);
        }else{
            if(s.empty())return false;
            char c = s.top();
            if((str[i]=='}'&&c=='{') || 
                (str[i]==')' && c=='(') || 
                (str[i]==']' && c=='[')){
                    s.pop();
            }else{
                return false;
            }
        }
        
    }
    if(s.empty()) return true;
    else return false;
}
int main(){
    string s = "([])]";
    if(balanceCheck(s))cout<<"True";
    else cout<<"NO";
    return 0;
}