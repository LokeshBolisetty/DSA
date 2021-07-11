#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> DistinctNumbersInWindow(vector<int> &A,int B){
    if(B==1)return vector<int>(A.size()-B+1,1);
    int n = A.size();
    vector<int> ans;
    map<int,int> m;
    for(int i=0;i<B;i++){
        m[A[i]]++;
    }
    ans.push_back(m.size());
    for(int i=1;i<n-B+1;i++){
        m[A[i-1]]--;
        if(m[A[i-1]]==0)m.erase(A[i-1]);
        m[A[i+B-1]]++;
        ans.push_back(m.size());
    }
    return ans;
}
int main(){
    vector<int> A = { 3, 3, 3, 3, 3, 3, 11, 11, 12, 12, 12, 16, 19, 19, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 53, 61, 61, 61, 61, 61, 61, 61, 63, 68, 68, 76, 76, 82, 86, 86, 86, 86, 86, 86, 86, 86, 95};
    int B = 3;
    vector<int> ans = DistinctNumbersInWindow(A,B);
    for(auto x:ans){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}