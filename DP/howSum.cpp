#include<iostream>
#include<vector>
using namespace std;
vector<int> howSum(int n,vector<int> num){
    vector<vector<int>> v(n+1,vector<int>(1,-1));
    for(int i=0;i<num.size();i++){
        vector<int> x;
        x.push_back(num[i]);
        if(num[i]<n+1)v[num[i]]=x;
    }
    v[0]={1};
    for(int i=1;i<n+1;i++){
        if(v[i][0]>0){
            for(int j=0;j<num.size();j++){
                int x = i+num[j];
                if(x>=n+1)continue;
                v[x]=v[i];
                v[x].push_back(num[j]);
            }
        }
    }
    return v[n];
}
int main(){
    vector<int> v = howSum(300,{7,14});
    for(int x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}