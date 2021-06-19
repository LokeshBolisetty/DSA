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
        if(B>=A[mid])low = mid;
        else high = mid-1;
    }
    if(low==0 && A[low]>B)return 0;
    return low+1;
}
int main(){
    vector<int> A = {1,3,3,3,6,6,6,6,6,7};
    cout<<LastTrue(A,2)<<endl;
    return 0;
}