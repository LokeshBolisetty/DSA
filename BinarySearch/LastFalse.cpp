#include<iostream>
#include<vector>
using namespace std;
bool compare(int target){
    return target>10;
}
//FFFFTTTT
int LastFalse(vector<int> A){
    int low = 0,high = A.size()-1;
    int mid;
    while(low<high){
        mid = low+(high-low+1)/2;//To check when to put low+high+1/2 and when to 
        // put low+high/2, narrow down the search base to F T
        // say the indices are 3 and 4 for them
        // if mid = low+high/2, then mid = 3 [mid]==false
        // So low = mid, high remains at 4. So you might run into infinite loop. 
        //Example of infinite loop condition -{ 2,5,8,10,13,17,24,78,90,100} predicate : target>10 
        if(compare(A[mid])==false)low = mid;
        else high=mid-1;
    }
    return A[low];
}
int main(){
    vector<int> A = { 2,5,8,10,13,17,24,78,90,100};
    cout<<LastFalse(A);
    return 0;
}