#include <bits/stdc++.h>
using namespace std;
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
*/
vector<vector<int>> ThreeSumZero(vector<int> &A){
    if(A.size()<3)return {};
    sort(A.begin(),A.end());
    vector<vector<int>> answer;
    int n = A.size();
    int B=0;
    for(int i=0;i<n-2;i++){
        if(i>0 && A[i] == A[i-1]) continue; //To ensure no duplicates
        int low = i+1;
        int high = n-1;
        while(low<high){
            long long int sum =(long long int) A[i] + A[low]+A[high];
            if(sum==B){
                answer.push_back({A[i],A[low],A[high]});
                while(low<n-1 && A[low]==A[low+1]){ //To ensure no duplicates
                    low++;
                }
                while(high>0 && A[high]==A[high-1]){ //To ensure no duplicates
                    high--;
                }
                low++;high--;
            };
            if(sum>B)high--;
            else if(sum<B)low++;
        }
    }
    return answer;
}
int main(){
    vector<int> A = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = ThreeSumZero(A);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}

//This works but just returns if it is possible to get a zero or not
// bool ThreeSumZero(vector<int> A){ 
//     int n = A.size();
//     if(n<3)return false;  
//     sort(A.begin(),A.end());
//     set<int> s;
//     for(int i=0;i<n-1;i++){
//         s.insert(A[i]+A[i+1]);
//     }
//     for(int i=0;i<n;i++){
//         if(s.find(-A[i])!=s.end())return true;
//     }
//     return false;
// }