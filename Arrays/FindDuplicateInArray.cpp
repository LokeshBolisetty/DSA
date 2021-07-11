#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int FindDuplicateInArray(vector<int> A){
    int n = A.size(); 
    if(n<=1) return -1; 
    int slow = A[0],fast = A[A[0]];
    while(slow!=fast){
        slow = A[slow];
        fast = A[A[fast]];
    }
    fast = 0;
    while(slow!=fast){
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}
int main(){
    vector<int> v = {3,4,1,4,1};
    cout<<FindDuplicateInArray(v)<<endl;
    return 0;
}