#include<iostream>
#include<vector>
using namespace std;
void combinations(int n,int k,vector<int> &A,vector<vector<int>> &ans,int st){
    if(k==0){
        ans.push_back(A);
        return;
    }
    for(int i=st;i<n;i++){
        A.push_back(i);
        combinations(n,k-1,A,ans,st+1);
        A.pop_back();
    }
}
vector<vector<int>> generateCombinations(int n,int k){
    vector<int> A;
    vector<vector<int>> ans;
    combinations(n,k,A,ans,1);
    return ans; 
}
int main(){
    vector<vector<int>> ans = generateCombinations(4,2);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
    return 0;
}