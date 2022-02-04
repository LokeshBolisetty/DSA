#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    //same number of 0s and 1s have been encountered when either count is 0 or when count same.
    int n = nums.size();
    unordered_map<int,int> m;
    int count = 0,ans=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1)count++;
        if(nums[i]==0)count--;
        if(count==0){
            ans = max(ans,i+1);
            continue;
        }
        if(m.find(count)!=m.end())ans = max(ans,i-m[count]);
        else m[count] = i;
    }
    return ans;
}

int findMaxLengthOptimal(vector<int> &nums){
    int n = nums.size();
    vector<int> tracker(2*n+1,-1);
    int count = 0, answer = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==1)count++;
        else count--;
        if(count==0)answer = max(i+1, answer);
        else if(tracker[count+n]!=-1)answer = max(answer,i-tracker[count+n]);
        else tracker[count+n]=i;
    }
    return answer;
}


int main(){
    // -1 -2 -3 -2 -1 0 1 -1 -2 -3
    // 9 - 2
    vector<int> v = {0,1};
    cout<<findMaxLengthOptimal(v)<<endl;
    return 0;
}