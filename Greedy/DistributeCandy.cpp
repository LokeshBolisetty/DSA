#include<iostream>
#include<vector>
using namespace std;
vector<int> distributeCandy(vector<int> &A){
    int n = A.size();
    vector<int> left(n,1),right(n,1);
    for(int i=1;i<A.size();i++){
        if(A[i]>A[i-1])left[i]=left[i-1]+1;
    }
    for(int i=n-2;i>=0;i--){
        if(A[i]>A[i+1])right[i]=right[i+1]+1;
    }
    for(int i=0;i<n;i++){
        left[i] = max(left[i],right[i]);
    }
    return left;
}
int main(){
    vector<int> rating = {1,2,3,1,1};
    vector<int> candies = distributeCandy(rating);
    for(int x:candies){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}