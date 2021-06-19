#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
The element on ith line jth position of a pascal's triangle is iCj

nCr = n!/(n-r)!*r!
nC(r-1) = n!/(n-r+1)!*(r-1)!
nCr = nC(r-1)*(n-r+1)/r
*/
void printPascal(int lines){
    int spaceCount=lines;
    for(int i =1;i<=lines;i++){
        int c = 1;
        for(int k=0;k<spaceCount;k++)cout<<" ";
        spaceCount--;
        for(int j=1;j<=i;j++){
            cout<<c<<" ";
            c = c*(i-j)/j;
        }
        cout<<endl;
    }
}
int main(){
    int n  = 10;
    printPascal(n);
    return 0;
}