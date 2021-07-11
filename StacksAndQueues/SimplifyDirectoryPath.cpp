#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string SimplifyDirectoryPath(string str){
    string answer = "";
    int size = str.size();
    vector<string> v;
    for(int i =0;i<size;i++){
        if(isalnum(str[i])){
            string k = "";
            while(isalnum(str[i]) && i<size){
                k += str[i];
                i++;
            }
            v.push_back(k);
        }else if(str[i]=='.' && str[i+1]=='.'){
            if(!v.empty())v.pop_back();
        }
    }
    if(!v.empty()){
    for(int i=0;i<v.size();i++){
        answer += '/'+ v[i];
    }
    return answer;
    }
    if(v.empty())return "/";
    return "/";
}
/*
INTERVIEW BIT SOLUTION
string Solution::simplifyPath(string A) {
    vector<string> s;
    for(int i = 0; i < A.length(); i++){
        if(isalnum(A[i])){
           string t = "";
           while(isalnum(A[i])) t += A[i++];
           s.push_back(t);
        }
        else if(A[i] == '.' && A[i+1] == '.'){
           if(!s.empty()) s.pop_back();
        }
    }

    string ans = ""; 
    if(!s.empty()){
        for(string &i: s){
            ans += "/"+i;
        }
        return ans;
    }
    return "/";

}

*/

int main(){
    string s;
    cin>>s;
    cout<<SimplifyDirectoryPath(s);
    return 0;
}