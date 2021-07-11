#include <iostream>
#include <vector>
using namespace std;
//Find out the first false 
//FFFFTTTT
bool compare(int target){
    return target>30;
}
//So in the example { 2,5,8,10,13,17,24,78,90,100} we should get the answer as 78
int FirstTrue(vector<int> A,int B){
    int low=0,high=A.size()-1;
    int mid = low+(high-low)/2;
    while(low<high){
        mid = low+(high-low)/2;
        if(B<=A[mid])high = mid;
        else low = mid+1;
    }
    return high;
}
int main(){
    vector<int> A = { 2,5,8,10,13,17,24,78,90,100};
    cout<<FirstTrue(A,13);
    return 0;
}