#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.
*/
int RemoveDuplicates(vector<int> &A){
    int n = A.size();
    if(n==0)return 0;
    //First mark all the repeated numbers with some dummy number. 
    //INT_MAX is used here. 
    for(int i=0;i<n-1;i++){
        int a = A[i]; int flag = false;
        while(i<n-1 && a==A[i+1]){ //To mark the second occurence of a
            flag=true;
            i++;
            break;
        }
        while(i<n-1 && flag && a==A[i+1]){ //From the thrid occurence we mark them with INT_MAX
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
    vector<int> A = {1,1,1,2};
    int len = RemoveDuplicates(A);
    for(int i=0;i<len;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    return 0;
}