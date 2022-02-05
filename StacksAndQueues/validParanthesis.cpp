/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


bool isValid(string &s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        switch (s[i])
        {
        case '(':
            st.push(s[i]);
            break;
        case '{':
            st.push(s[i]);
            break;
        case '[':
            st.push(s[i]);
            break;
        case ']':
            if(!st.empty() && st.top()=='[')st.pop();
            else return false;
            break;
        case '}':
            if(!st.empty() && st.top()=='{')st.pop();
            else return false;
            break;
        case ')':
            if(!st.empty() && st.top()=='(')st.pop();
            else return false;
            break;
        default:
            //If any unexpected characters appear
            return false;
        }
    }
    return st.empty();
}

int main(){
    string s = "(){[]";
    cout<<boolalpha<<isValid(s)<<endl;
    return 0;
}