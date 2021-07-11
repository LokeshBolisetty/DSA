#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<vector<int>> fourSum(vector<int> &A,int B){
    if(A.size()<4)return {};
    vector<vector<int>> ans;
    int n = A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int left = j+1;
            int right = n-1;
            while(left<right){
                int sum = A[i]+A[j]+A[left]+A[right];
                if(sum==B){
                    ans.push_back({A[i],A[j],A[left],A[right]});
                    while(left+1<n && A[left]==A[left+1])left++;
                    while(right-1>left && A[right]==A[right-1])right--;
                    left++;
                    right--;
                }else if(sum<B)left++;
                else right--;
            }
            while(j+1<n && A[j+1]==A[j])j++;
        }while(i+1<n && A[i+1]==A[i])i++;
    }
    return ans;
}

int main(){
    vector<int> A = {1,0,-1,0,-2,2};
    vector<vector<int>> v = fourSum(A,0);
    for(auto x:v){
        for(auto y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
    return 0;
}