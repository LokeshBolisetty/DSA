#include<iostream>
#include<vector>

using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &rack)
{
    //First one is the sum, second is the value
	vector<pair<int,int>> dp;
    dp.push_back({rack[0], rack[0]});
    int answer = rack[0];
    for(int i=1;i<rack.size();i++){
        int maxi = rack[i];
        for(int j=0;j<i;j++){
            if(dp[j].second<rack[i]){
                maxi = max(maxi, dp[j].first+rack[i]);
            }
        }
        dp.push_back({maxi, rack[i]});
        answer = max(answer, dp.back().first);
    }
    return answer;
}

int main(){
    vector<int> v = {9,1,2,8};
    cout<<maxIncreasingDumbbellsSum(v)<<endl;
    return 0;
}