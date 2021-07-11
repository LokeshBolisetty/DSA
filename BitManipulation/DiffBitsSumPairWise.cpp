#include<iostream>
#include<vector>
using namespace std;
int DiffBitsSumPairWise(vector<int> &A){
    long long int answer = 0;
    #define MOD 1000000007;
    for(int i=0;i<31;i++){
        int count=0;
        for(int j=0;j<A.size();j++){
            if(A[j] & (1<<i))count++;
        }
        answer += count*(A.size()-count)*2;
        answer %= MOD;
    }
    return (int)answer%MOD;
    // long long int ans = 0;
    // int count;
    // for(int i = 0; i < 31; i++){
    //     count = 0;
    //     for(int j = 0; j < A.size(); j++){
    //         if(A[j] & (1 << i)){
    //             count++;
    //         }
    //     }
    //     ans = ans + (2*count*(A.size()-count));
    //     ans = ans%mod;
    // }
    
    // return (int)ans;
}
int main(){
    vector<int> A = {1,3,5};
    cout<<DiffBitsSumPairWise(A)<<endl;
    return 0;
}