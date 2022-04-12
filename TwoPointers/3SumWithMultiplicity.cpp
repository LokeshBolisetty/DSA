#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

int threeSumMulti(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n-2;i++){
        int j = i+1,k = n-1;
        while(j<k){
            int candidate = arr[i]+arr[j]+arr[k];
            if(candidate<target)j++;
            else if(candidate>target)k--;
            else{
                //count = (count+1)%MOD;

                //Skip all arr[k]s
                int arrk = arr[k];
                k--;
                int kMul = 1;
                while(arr[k]==arrk && k>j){
                    kMul++;
                    k--;
                }
                
                //Skip arr[j]s
                int arrj = arr[j];
                j++;
                int jMul=1;
                while(arr[j]==arrj && j<=k){
                    jMul++;
                    j++;
                }
                count = (count+(kMul*jMul))%MOD;
            }
        }
    }
    return count;
}

int main(){
    vector<int> A = {1,1,2,2,3,3,4,4,5,5};
    cout<<threeSumMulti(A,8)<<endl;
    return 0;
}