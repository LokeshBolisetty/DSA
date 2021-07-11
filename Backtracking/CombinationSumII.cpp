#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> combination(vector<int> A,int B,int st){
    vector<vector<int>> ans;
    for(int i=st;i<A.size() && A[i]<=B;i++){
        if(A[i]==B){
            ans.push_back({B});
        }
        else if(A[i]>B)continue;
        else{
            int k = A[i];
            A.erase(A.begin()+i);
            vector<vector<int>> p = combination(A,B-k,st);
            if(p.size()!=0){
                for(int t=0;t<p.size();t++){
                    p[t].insert(p[t].begin(),k);
                    sort(p[t].begin(),p[t].end());
                    ans.push_back(p[t]);
                }
            }
            // for(int j=0;j<A.size();j++){
            //     vector<vector<int>> p = combination(A,B-k,x);
            //     if(p.size()!=0){
            //         for(int t=0;t<p.size();t++){
            //             p[t].push_back(A[i]);
            //             ans.push_back(p[t]);
            //         }
            //     }
            // }
            A.insert(A.begin()+i,k);
        }
    }
    sort(ans.begin(),ans.end());
    auto it = unique(ans.begin(),ans.end());
    vector<vector<int>> a;
    for(auto ip=ans.begin();ip!=it;ip++){
        a.push_back(*ip);
    }
    return a;
}
vector<vector<int>> CombinationSum(vector<int> &A,int B){
    sort(A.begin(),A.end());
    return combination(A,B,0);
}
int main(){
    vector<int> A = {10,1,2,7,6,1,5};
    vector<vector<int>> ans = CombinationSum(A,8);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}