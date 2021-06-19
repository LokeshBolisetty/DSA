#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
vector<int> PrimeSum(int n){
     vector<int> v;
    for(int i=2;i<=n/2;i++)
    {
        if( isPrime(i) && isPrime(n-i) )
        {
            v.push_back(i);
            v.push_back(n-i);
            return v;
        }
    }
}
int main(){
    int n=10;
    vector<int> answer=PrimeSum(n);
    cout<<answer[0]<<" "<<answer[1]<<endl;
    return 0;
}