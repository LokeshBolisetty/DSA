#include<bits/stdc++.h>
using namespace std;
//Remove Duplicates from a sorted array and return the resulting size
int RemoveDuplicates(vector<int> &A){
    int n = A.size();
    if(n==0)return 0;
    //First mark all the repeated numbers with some dummy number. 
    //INT_MAX is used here. 
    for(int i=0;i<n-1;i++){
        int a = A[i];
        while(i<n-1 && a==A[i+1]){
            A[i+1]=INT_MAX;
            i++;
        }
    }
    while(A[n-1]==INT_MAX) //If the last element of the array is a duplicate number then we dont need to go upto there
        n--;
    int i=0,j = 0;
    for(;i<n, j<n;i++,j++){
        while(j<n && A[j]==INT_MAX){ //Skip all the duplicate numbers and take the next unique number
            j++;
        }
        A[i]=A[j]; // Assign that unique number to the array
    }
    return i; // The number of times the loop ran is equal to the length of the array of unique numbers.
}
int main(){
    vector<int> A = {};
    int n = RemoveDuplicates(A);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    return 0;
}