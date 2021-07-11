#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int x,m,d;
        cin>>x>>m>>d;
        cout<<min(x+d,x*m)<<endl;
    }
    return 0;
}