/*
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.
*/
#include<bits/stdc++.h>
using namespace std;
int someoneOneLeetcode(int k, int A, int B, int C) {
    int lo = 1, hi = 2 * (int) 1e9;
    long a = long(A), b = long(B), c = long(C);
    long ab = a * b / __gcd(a, b);
    long bc = b * c / __gcd(b, c);
    long ac = a * c / __gcd(a, c);
    long abc = a * bc / __gcd(a, bc);
    while(lo < hi) {
        int mid = lo + (hi - lo)/2;
        int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
        if(cnt < k) 
            lo = mid + 1;
        else
            //the condition: F(N) >= k
            hi = mid;
    }
    return lo;
}
int main(){
    int n = 10;
    int a = 2, b= 3, c = 5;
    cout<<someoneOneLeetcode(n,a,b,c)<<endl;
    return 0;
}