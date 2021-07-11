#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int T;
    cin>>T;
    while(T--){
       int n,k,f;
       cin>>n>>k>>f;
       int pe=0;
       int count=0;
       for(int i =0;i<n;i++){
           int s,e;
           cin>>s>>e;
           if(s>pe){
               count+=(s-pe);
           }pe=e;
       }count+=(f-pe);
       if(count>=k)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}