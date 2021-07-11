#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string ReverseTheString(string A){
    int n = A.size();
    if(n==1)return A;//Added this because of line 13. it will return "" for length 1
    if(A=="")return "";
    int j=0;
    string answer = "";
    while(j<n && A[j]==' '){
        j++;
    }
    if(j==n-1)return "";
    int i =n-1;
    while(i>=j && A[i]==' '){
        i--;
    }
    bool flag=false;
    while(i>=j){
        int start = i,size=0;
        if(flag)answer+=" ";
        while(i>=j && A[i]!=' '){
            i--;
            size++;
        }
        answer+=A.substr(i+1,size);
        while(i>=j && A[i]==' ')i--;
        flag=true;
    }
    return answer;
}
int main(){
    //string s = "the sky is blue and the land is green";
    string s = "j";
    cout<<ReverseTheString(s)<<endl;
    return 0;
}