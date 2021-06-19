#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> kthRowOfPascalTriangle(int A){
     A++; //Converting from 0 index to 1 indexing
    vector<int> answer;
    long long int c=1;
    for(int i =1;i<=A;i++){
        answer.push_back(int(c));
        /*
        The element on ith line jth position of a pascal's triangle is iCj
        
        nCr = n!/(n-r)!*r!
        nC(r-1) = n!/(n-r+1)!*(r-1)!
        nCr = nC(r-1)*(n-r+1)/r
        */
        c = c*(A-i)/i;
    }
    return answer;
}
int main(){
    int k=4;
    // Output should be 1 4 6 4 1
    vector<int> v = kthRowOfPascalTriangle(k);
    for(int i =0;i<k;i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}