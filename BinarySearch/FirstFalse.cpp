#include <iostream>
#include <vector>
using namespace std;
//Find out the first false 
//TTTTFFFF
bool compare(int target){
    return target<50;
}
//So in the example { 2,5,8,10,13,17,24,78,90,100} we should get the answer as 78
int FirstFalse(vector<int> A){
    int low=0,high=A.size();
    int mid = low+(high-low)/2;
    while(low<high){
        mid = low+(high-low)/2;
        if(compare(A[mid]))low = mid+1;
        else high = mid;
    }
    return A[low];
}
int main(){
    vector<int> A = { 2,5,8,10,13,17,24,78,90,100};
    cout<<FirstFalse(A);
    return 0;
}