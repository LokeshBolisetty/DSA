#include<iostream>
#include<vector>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> x;
    x.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>x.back()){
            x.push_back(arr[i]);
        }else{
            int idx = lower_bound(x.begin(), x.end(), arr[i]) - x.begin();
            x[idx] = arr[i];
        }
    }
    return x.size();
}

int main(){
    int arr[] = {5,4,11,1,16,8};
    cout<<longestIncreasingSubsequence(arr, 6)<<endl;
    return 0;
}