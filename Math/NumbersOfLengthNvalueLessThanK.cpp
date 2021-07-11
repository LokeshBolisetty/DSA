#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

//Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.
//  NOTE: All numbers can only have digits from the given set. 

using namespace std;

vector<int> numToVec(int N){
    vector<int> A;
    while(N!=0){
        A.push_back(N%10);
        N/=10;
    }
    if(A.size()==0){
        A.push_back(0);
    }
    reverse(A.begin(),A.end());
    return A;
}

int solve(vector<int> A,int B,int C){
    vector<int> digits = numToVec(C);
    int d,d2;
    d = A.size();
    if(B>digits.size()||d==0)return 0;
    else if(B<digits.size()){
        if(A[0]==0)return pow(d,B-1)*(d-1);
        return pow(d,B);
    }else{
        vector<int> dp(B+1,0);
        vector<int> lower(11,0);
        for(int i=0;i<d;i++){
            lower[A[i]+1]=1;
        }
        for(int i=1;i<=10;i++){
            lower[i]=lower[i-1]+lower[i];
        }
        bool flag = true;
        dp[0]=0;
        for(int i=1;i<=B;i++){
            d2=lower[digits[i-1]];
            dp[i]=dp[i-1]*d;
            if (i == 1 && A[0] == 0 && B != 1)
                d2 = d2 - 1;
 
            // Whether (i-1) digit of generated number
            // can be equal to (i - 1) digit of C
            if (flag)
                dp[i] += d2;
 
            // Is digit[i - 1] present in A ?
            flag = (flag & (lower[digits[i - 1] + 1]
                            == lower[digits[i - 1]] + 1));
            }
        return dp[B];
    }
}

int main(){
    cout<<solve({0,1,5},1,2)<<endl;
    cout<<solve({0,1,2,5},2,21)<<endl;
    cout<<solve({},1,1)<<endl;
    return 0;
}