#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AntiDiagonals(vector<vector<int>> A){
    int n = A.size();
    vector<vector<int>> answer(2*n-1);
    for(int i =0;i<n;i++){
        int j=i,k=0;
        while(j>=0){
            answer[i].push_back(A[k][j]);
            j--;k++;
        }
    }
    int previ=0,j=n-1;
    for(int idx=n;idx<2*n;idx++){
        int i=previ+1;j=n-1;
        previ=i;
        while(i<n && j>=0){
            answer[idx].push_back(A[i][j]);
            i++;j--;
        }
    }
    return answer;
}
vector<vector<int>> Editorial(vector<vector<int>> A){
    int n = A.size();
    int N = 2*(n-1) + 1;//number of vectors in ans
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(A[i][j]);//sum of index values in 2d array gives the index in ans
    }
    return ans;
}
int main()
{
    vector<vector<int>> A = {{2,3,4,5},
                             {9,0,8,7},
                             {6,4,3,8},
                             {2,6,4,9}};
    A = AntiDiagonals(A);
    for(int i =0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}