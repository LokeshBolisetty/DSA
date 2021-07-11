#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> howSum(int n,vector<int> num){
    vector<vector<int>> res;
    vector<vector<int>> v(n+1,vector<int>(1,-1));
    for(int i=0;i<num.size();i++){
        vector<int> x;
        x.push_back(num[i]);
        if(num[i]<n+1)v[num[i]]=x;
    }
    v[0]={1};
    if(v[n][0]>0)res.push_back(v[n]);
    for(int i=1;i<n+1;i++){
        if(v[i][0]>0){
            for(int j=0;j<num.size();j++){
                int x = i+num[j];
                if(x>=n+1)continue;
                v[x]=v[i];
                v[x].push_back(num[j]);
                if(x==n){
                    sort(v[n].begin(),v[n].end());
                    res.push_back(v[n]);
                }
            }
        }
         if(v[n][0]>0){
            sort(v[n].begin(),v[n].end());
            res.push_back(v[n]);
        }
    }
    sort(res.begin(),res.end());
    auto ip = unique(res.begin(),res.end());
    vector<vector<int>> r;
    for(auto it=res.begin();it!=ip;it++){
        r.push_back(*it);
    }
    return r;
}
int main(){
    vector<vector<int>> v = howSum(4,{1,2});
    for(auto x:v){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}