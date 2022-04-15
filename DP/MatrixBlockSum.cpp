#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++)mat[i][j] += mat[i][j-1];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<"\t";
        }cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> answer(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val=0;
            int  o = max(0,i-k);
            int downLimit = min(m-1,i+k);
            while(o <= downLimit){
                val += mat[o][min(j+k,n-1)];
                val -= j-k-1<0?0:mat[o][j-k-1];
                o++;
            }
            answer[i][j] = val;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    mat = matrixBlockSum(mat,2);
    int m = mat.size(), n = mat[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<"\t";
        }cout<<endl;
    }
    return 0;
}