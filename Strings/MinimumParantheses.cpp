#include<iostream>
#include<stack>
using namespace std;
int MinimumParantheses(string A){
    //This passed all test cases but can be optimized. Since th
    //question uses only ( and ) you dont need a stack. A simple variable will 
    //do the job. See editorial function for the same. 
    stack<char> s;
    int count=0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]=='(')s.push(A[i]);
        else{
            if(!s.empty())s.pop();
            else count++;
        }
    }
    return count+s.size();
}
int Editorial(string a){
      int openBrackets = 0, req=0;
    for(int i=0;i<a.length();i++) {
        if(a[i]=='(') {
            openBrackets++;
        } else {
            if(openBrackets>0) openBrackets--;
            else {
                req++;
            }
        }
    }
    req+=openBrackets;
    return req;
}

int main(){
    string A = "(())))((";
    cout<<Editorial(A)<<endl;
    return 0;
}