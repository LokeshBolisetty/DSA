#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void generate(int n, vector<int> &A,vector<vector<int>> &ans,vector<int> &row,int st){
    if(n==0)ans.push_back(row);
    for(int i=st;i<A.size();i++){
        if(n==A[i]){
            row.push_back(A[i]);
            ans.push_back(row);
            row.pop_back();
            return;
        }
        else if(n<A[i])return;
        row.push_back(A[i]);
        generate(n-A[i],A,ans,row,i);
        row.pop_back();
    }
    return;
}
vector<vector<int>> comb(int n, vector<int> &A){
    sort(A.begin(),A.end());
    vector<int> row;
    vector<vector<int>> ans;
    generate(n,A,ans,row,0);
    sort(ans.begin(),ans.end());
    auto it = unique(ans.begin(),ans.end());
    vector<vector<int>> a;
    for(auto ip=ans.begin();ip!=it;ip++){
        a.push_back(*ip);
    }
    return a;
    return ans;
}
int main(){
    vector<int> A = {1,2};
    vector<vector<int>> v = comb(4,A);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}