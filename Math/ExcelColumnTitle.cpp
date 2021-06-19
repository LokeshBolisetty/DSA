#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
string ExcelColumnTitle(int A){
    string s="";
    while(A>0){
        int rem = A%26;
        if(rem==0){
            s='Z'+s;
            A = A/26 -1;
        }else{
            char c = rem+'A'-1;
            s=c+s;
            A = A/26;
        }
    }
    return s;
}
int main(){
    int A = 590; //answer should be AB
    for(int i=0;i<A;i++)
    cout<<i<<"\t"<<ExcelColumnTitle(i)<<endl;
    return 0;
}