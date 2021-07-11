/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void generate(vector<int> &A,vector<vector<int>> &ans,vector<int> &temp,int st){
    ans.push_back(temp);
    for(int i=st;i<A.size();i++){
        temp.push_back(A[i]);
        generate(A,ans,temp,i+1);
        temp.pop_back();
        while(i+1<A.size() && A[i]==A[i+1])i++;
    }
    return;
}
vector<vector<int>> generateAllSubsets(vector<int> A){
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    generate(A,ans,temp,0);
    sort(ans.begin(),ans.end());
    return ans;
    // auto it = unique(ans.begin(),ans.end());
    // vector<vector<int>> a;
    // for(auto ip=ans.begin();ip!=it;ip++){
    //     a.push_back(*ip);
    // }
    // return a;
}
int main(){
    vector<int> A = {1,2,2};
    vector<vector<int>> subsets = generateAllSubsets(A);
    for(int i=0;i<subsets.size();i++){
        for(int j=0;j<subsets[i].size();j++){
            cout<<subsets[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}