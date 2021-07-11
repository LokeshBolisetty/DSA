#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.
*/
int RemoveElement(vector<int> &A,int B){
    //non-B element = any number other than B
    int n = A.size();
    int i=0,j=-1; //j is initialized to -1 so that even if the size of array is 1 we still get correct answer
    while(i<n && j<n-1){
        if(A[i]==B){ //If the element at i is B then we should remove it. 
        //Removing is done by swapping it with a non-B element
        // So we need to find the first non-B element after i
            if(j<=i)j=i+1; //If j<=i then we set it to i+1. If its already >i it means that in previous iterations
            // it checked upto j and didnt find a non-B element
            while(j<n && A[j]==B)j++; //Move j until you find a non-B element
            if(j>=n || A[j]==B)break; //If you reach the end of the array, that need not necessarily mean that you found a non-B element
            //It might also stop there because j==n-1. So check if the A[j] is non-B. If its B, then it means we didnt find any non-B
            //We can stop here
            swap(A[i],A[j]);//Swap the element at i with the non-B element we just found.
        }
        i++; 
    }
    return i;//The max number of non-B we found is equal to i which is also equal to the length of the resulting array. 
}
int main(){
    vector<int> A = {2};
    int B = 3;
    int len = RemoveElement(A,B);
    cout<<"Length is "<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    return 0;
}
int RemoveElement2(vector<int> &A,int B){
    //This doesn't give the correct solution. 
    // If the array is [4,1,1,2,1,3] and we need to remove 1, they expect [4,2,3]
    // but this function returns [4,3,2]
    //Apart from that "I think" it works  
    int n = A.size();
    int i=0,j=n-1;
    while(j>=0 && A[j]==B)j--;
    while(i<n && j>-1 && i<j){
        if(A[j]==B){
            j--;
            continue;
        }
        if(A[i]==B){
            swap(A[i],A[j]);
        }
        i++;
    }
    return i;
}