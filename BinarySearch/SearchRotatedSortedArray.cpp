#include<iostream>
#include<vector>
using namespace std;
int FindIndex(vector<int> A,int i,int j){
    int mid = (i+j)/2;
    if(A[mid]>A[mid+1])return mid+1;
    else{
        if(A[i]<=A[mid])return FindIndex(A,mid+1,j);
        else return FindIndex(A,i,mid-1);
    }
}
int binarySearch(vector<int> A, int target,int i,int j){
    int low=i,high=j;
    while(low<high){
        int mid = low+(high-low)/2;
        if(A[mid]<target)low =mid+1;
        else high = mid; 
    }
    if(A[low]==target)return low;
    else return -1;
}
int Search(vector<int> A,int B){
    int pivot = FindIndex(A,0,A.size());
    if(A.size()==pivot)return binarySearch(A,B,0,A.size());
    if(A[A.size()-1]>=B){
        //Binary search in pivot to A.size()
        return binarySearch(A,B,pivot,A.size()-1);
    }else{
        //Binary search in 0 to pivot-1
        return binarySearch(A,B,0,pivot-1);
    }
}
int Editorial(vector<int> A, int B){
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid] == B) return mid;
        else if(A[0]<=A[mid]){//i.e. left part is sorted
            if(A[0]<=B && B < A[mid]) high = mid-1;//B lies on left part
            else low = mid+1;
        }else{//right part is sorted
            if(A[mid] < B && B<=A[n-1]) low = mid+1;//B lies on right part
            else high = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> A = {1,7,67,133,178};
    cout<<Editorial(A,67)<<endl;
    return 0;
}