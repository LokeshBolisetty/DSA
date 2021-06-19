#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Atoi(string A){
    if(A=="")return 0;
    int i =0,n=A.size();
    while(i<n && A[i]==' ')i++;//ignoring leading spaces
    int sign=1;
    if(A[i]=='-'){sign = -1;i++;}
    else if(A[i]=='+')i++;
    long long answer=0;
    int j = n-1;
    int p=i;
    for(;p<n;p++){ //Last character as digit
        if(A[p]<'0' || A[p]>'9')break;
    }
    while(i<p){
        answer=answer*10+(A[i]-'0');
        if(answer>INT_MAX)if(sign==1)return INT_MAX;else return INT_MIN;
        i++;
    }
    return sign*answer;
}
int main(){
    string A = "5121478262 8070067M75 X199R 547 8C0A11 93I630 4P4071 029W433619 M3 5 14703818 776366059B9O43393";
    cout<<Atoi(A)<<endl;
    return 0;
}