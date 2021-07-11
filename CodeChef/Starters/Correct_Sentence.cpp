#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int T;
    cin>>T;
    while(T--){
        int K;
        cin>>K;
        bool flag = true;
        for(int i =0;i<K && flag;i++){
            string s;cin>>s;
            char N = 'N',Z = 'Z',a='a',m='m',c=s[0];
            if(a<=c && c<=m){
                for(int j=0;j<s.size();j++){
                    c = s[j];
                    if(a>c || c>m){
                        flag = false;
                        break;
                    }
                }
            }else if(N<=c && c<=Z){
                for(int j=0;j<s.size();j++){
                    c = s[j];
                    if(N>c && c>Z){
                        flag = false;
                        break;
                    }
                }
            }else flag = false;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}