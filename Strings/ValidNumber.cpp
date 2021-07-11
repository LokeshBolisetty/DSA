#include<iostream>
using namespace std;
int isNumber(const string A){
    int dot=0,E=0,n=A.size(),minus=0;
    int i=0;
    while(i<n && A[i]==' ')i++;
    if(i==n)return 0;
    if(A[i]=='-')i++;
    for(;i<n;i++){
        if(A[i]=='-'){
            if(A[i-1]=='e')continue;
        }
        if(A[i]==' '){
            i++;
            while(i<n){
                if(A[i]!=' ')break;
                i++;
            }
            if(i!=n)return 0;
            else return 1;
        }
        if(isdigit(A[i]))continue;
        if(A[i]=='.'){
            if(E)return 0;
            if(i==n-1 || A[i+1]=='e')return 0;
            if(dot>0)return 0;
            if(i==n-1) return 0;
            dot++;
        }else if(A[i]=='e'){
            if(i==n-1)return 0;
            if(E>0)return 0;
            E++;
        }else return 0;
    }
    return 1;
}
int main(){
    string A = "1.e";
    cout<<isNumber(A)<<endl;
}