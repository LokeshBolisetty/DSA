#include<iostream>
#include <vector>
using namespace std;
bool compare(int target){
    return target<20;
}
//TTTTFFFF
int LastTrue(vector<int> A){
    int low = 0,high = A.size()-1;
    int mid;
    while(low<high){
        mid = low+(high-low+1)/2;
        if(compare(A[mid]))low = mid;
        else high = mid-1;
    }
    return A[low];
}
int main(){
    vector<int> A = { 2,5,8,10,13,17,24,78,90,100};
    cout<<LastTrue(A);
    return 0;
}