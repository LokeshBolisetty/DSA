#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int ExcelColumnNumber(string A){
    int n=A.length();
    int col=0;int p = 1;
    for(int i=n-1;i>=0;i--){
        char c = A[i];
        int a = int(c);
        col+=p*(int(A[i])-'A'+1);
        p*=26;
    }
    return col;
}

int main(){
    string S = "AZ";
    cout<<ExcelColumnNumber(S)<<endl;
    return 0;
}