#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int T;
    cin>>T;
    while(T--){
       int n,m,k;
       cin>>n>>m>>k;
       vector<int> arr(n);
       int v[k];
       int count=0;
       
       for(int i =0;i<k;i++){
           int t;cin>>t;
           if(t<=n){
               arr[t-1]++;
               if(arr[t-1]=2)count++;
           }
       }
       if(k<=n){
           cout<<0<<endl;
           continue;
       }
       cout<<count<<" ";
        for(int i =0;i<n;i++){
            if(arr[i]>1)
                cout<<i+1<<" ";
        }cout<<endl;
    }
    return 0;
}