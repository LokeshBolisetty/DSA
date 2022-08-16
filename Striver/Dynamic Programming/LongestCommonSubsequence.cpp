#include<iostream>
#include<vector>

using namespace std;

int lcs(string s, string t)
{
	int n = s.length(), m = t.size();
    vector<vector<int>> dp(n,vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                if(i>0 && j>0)dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = 1;
            }else{
                int a = 0, b = 0;
                if(i>0)a = dp[i-1][j];
                if(j>0)b = dp[i][j-1];
                dp[i][j] = max(a,b);
            }
        }
    }
    return dp[n-1][m-1];
}

int main(){
    string s = "adebc", t = "dcadb";
    cout<<"The length of the longest common subsequence is "<<lcs(s, t)<<endl;
    return 0;
}