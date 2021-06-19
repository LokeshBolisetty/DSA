#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Wood(vector<int> &A,int B,int target){
    //target is what he will set the height as
    int sum=0;
    for(int i=0;i<A.size();i++){
        if(A[i]>target)sum+=(A[i]-target);
        if(sum>=B)return true;
    }
    if(sum>=B)return true;
    return false;
}
//TTTTFFFF
int LastTrue(vector<int> A,int B){
    if(A.size()==0)return 0;
    int low = 0,high = *max_element(A.begin(),A.end());
    int mid;
    while(low<high){
        mid = low+(high-low+1)/2;
        if(Wood(A,B,mid))low = mid;
        else high = mid-1;
    }
    return low;
}
int main(){
    vector<int> A = {5};
    cout<<LastTrue(A,4)<<endl;
    return 0;
}