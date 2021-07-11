#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int nCr(int n,int r){
    //O(r) time and O(1) space
    int res = 1;
    if (r > n - r)
        r = n - r;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
int main(){
    int n = 10;
    int r = 5;
    cout<<nCr<<endl;
    return 0;
}