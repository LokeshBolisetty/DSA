#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//CPP code written here doesnt work. Use this from Java
/*
public class Solution {
    public String solve(int A) {
        java.math.BigInteger f = new java.math.BigInteger("1"); 
        for (int i = 2; i <= A; i++)
            f = f.multiply(java.math.BigInteger.valueOf(i));
        String s = f.toString();
        return s;
    }
}
*/
string Factorial(int A) {
    long long int f=1;
    for(int i =1;i<=A;i++){
        f=f*i;
        cout<<f<<endl;
    }
    cout<<f<<endl;
    return to_string(f);
}

int main(){
    int s;
    cin>>s;
    cout<<Factorial(s)<<endl;
    return 0;
}