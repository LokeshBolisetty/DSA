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
int main(){
    int n=17;
    for(int i=0;i<100;i++)
        cout<<i<<" is "<<isPrime(i)<<endl;
    return 0;
}