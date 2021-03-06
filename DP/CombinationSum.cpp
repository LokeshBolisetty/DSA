/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void back(vector<int> &candidates, int target,vector<vector<int>> &ans,vector<int> &curr,int idx){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(idx==candidates.size() || candidates[idx]>target)return;
    curr.push_back(candidates[idx]);
    back(candidates,target-candidates[idx],ans,curr,idx);
    curr.pop_back();
    back(candidates,target,ans,curr,idx+1);
}

vector<vector<int>> combinationSum(vector<int> &candidates,int target){
    //Far better solution
    vector<vector<int>> answer;
    vector<int> curr;
    sort(candidates.begin(),candidates.end());
    back(candidates,target,answer,curr,0);
    return answer;
}

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