#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> A, int target){
    int low=0,high=A.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(A[mid]<target)low =mid+1;
        else high = mid; 
    }
    if(A[low]==target)return low;
    else return -1;
    return low;
}
int main(){
    vector<int> A = { 2,5,8,10,13,17,24,78,90,100};
    cout<<binarySearch(A,91)<<endl;
    return 0;
}