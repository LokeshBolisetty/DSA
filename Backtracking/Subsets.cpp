#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void generate(vector<int> &nums,int idx,vector<int> &v,vector<vector<int>> &answer){
    if(idx==nums.size()){
        answer.push_back(v);
        return;
    }
    //At every step, we either include the ith element or we dont. 
    generate(nums,idx+1,v,answer);
    v.push_back(nums[idx]);
    generate(nums,idx+1,v,answer);
    v.pop_back();
    return;
}

vector<vector<int>> generateAllPossibleSubsets(vector<int> &nums){
    vector<vector<int>> answer;
    vector<int> v;
    generate(nums,0,v,answer);
    return answer;
}

void generate(vector<int> &A,vector<vector<int>> &ans,vector<int> &temp,int st){
    ans.push_back(temp);
    for(int i=st;i<A.size();i++){
        temp.push_back(A[i]);
        generate(A,ans,temp,i+1);
        temp.pop_back();
    }
    return;
}
vector<vector<int>> generateAllSubsets(vector<int> A){
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    generate(A,ans,temp,0);
    return ans;
}
int main(){
    vector<int> A = {1,2,3};
    vector<vector<int>> subsets = generateAllSubsets(A);
    for(int i=0;i<subsets.size();i++){
        for(int j=0;j<subsets[i].size();j++){
            cout<<subsets[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}