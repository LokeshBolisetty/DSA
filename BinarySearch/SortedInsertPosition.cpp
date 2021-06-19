#include<iostream>
#include <vector>
using namespace std;
bool compare(int target){
    return target<20;
}
//TTTTFFFF
int LastTrue(vector<int> A,int B){
    int low = 0,high = A.size()-1;
    int mid;
    while(low<high){
        mid = low+(high-low+1)/2;
        if(A[mid]<=B)low = mid;
        else high = mid-1;
    }
    if(low==0)if(A[low]>B) return 0;//For FFFFFFF case
    if(A[low]==B)return low;
    return low+1;
}
int main(){
    vector<int> A = { 2,3,5,6};
    int B = 1;
    cout<<LastTrue(A,B);
    return 0;
}