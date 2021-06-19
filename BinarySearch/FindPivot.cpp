#include<iostream>
#include<vector>
using namespace std;
//In a sorted rotated array, find the pivot(the starting index of the 
//original sorted array)
int FindIndex(vector<int> A,int i,int j){
    int mid = (i+j)/2;
    if(A[mid]>A[mid+1])return mid+1;
    else{
        if(A[i]<=A[mid])return FindIndex(A,mid+1,j);
        else return FindIndex(A,i,mid-1);
    }
}

int main(){
    vector<int> A = {9,12,15,17,25,28,5,7,8};
    cout<<FindIndex(A,0,A.size()-1)<<endl;
    return 0;
}