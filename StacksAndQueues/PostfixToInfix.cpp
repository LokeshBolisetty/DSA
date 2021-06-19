#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int evaluate(string s){
    for(int i =0;i<s.size();i++){
        
    }
}
int PostfixToInfix(vector<string> A){
    stack<string> s;
    for(int i =0;i<A.size();i++){
        string c = A[i];
        if(c!="*" && c!="/" && c!="+" && c!="-"){
            s.push(c);
        }else{
            string a,b;
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            switch (c[0])
            {
            case '+':
                s.push(to_string(stoi(b)+stoi(a)));
                break;
            case '-':
                s.push(to_string(stoi(b)-stoi(a)));
                break;
            case '*':
                s.push(to_string(stoi(b)*stoi(a)));
                break;
            case '/':
                s.push(to_string(stoi(b)/stoi(a)));
                break;
            default:
                break;
            }
        }
    }
    return stoi(s.top());
}
int main(){
    int n;
    cin>>n;
    vector<string> A;
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        A.push_back(s);
    }
    cout<<PostfixToInfix(A)<<endl;

    return 0;
}