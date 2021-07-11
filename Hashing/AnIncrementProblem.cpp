#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> IncrementProblem(vector<int> &A){
    unordered_map<int,pair<int,int>> m;
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        if(m.find(A[i])==m.end()){
            m.insert({A[i],{1,i}});
        }else{
            m[A[i]].first++;
            m[A[i]].second = i;
        }
    }
    for(int i=0;i<A.size();i++){
        if(m.find(A[i])==m.end()){
            ans.push_back(A[i]);
        }else{
            pair<int,int> p = m[A[i]];
            if(p.second==i)ans.push_back(A[i]);
            else ans.push_back(A[i]+1);
        }
    }
    return ans;
}

int main(){
    vector<int> v= {2,2,4,4,2,4};
    v = IncrementProblem(v);
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}