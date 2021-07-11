#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> twoSum(const vector<int> A,int B){
    unordered_map<int, int> m;
    for(int i=0;i<A.size();i++){
        if(m.find(B-A[i])!=m.end()){
            return {m[B-A[i]],i+1};
        }else{
            if(m.find(A[i])==m.end())m[A[i]] = i+1;
        }
    }
    return {};
}

int main(){
    vector<int> A = {2,7,11,15};
    vector<int> ans = twoSum(A,9);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    return 0;
}