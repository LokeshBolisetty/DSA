/*
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> WaveArray(vector<int> A){
    //Basically just sort the array and swap adjacent elements 
    int n  = A.size();
    if(n%2==1)n--; //If the array is of odd length you can't swap the last element so taking care of that now itself.
    sort(A.begin(),A.end());
    for(int i =0;i<n;i=i+2){
        int t = A[i];
        A[i] = A[i+1];
        A[i+1] = t;
    }
    return A;
}
int main(){
    vector<int> A = {1,2,3,56,2,4,8,90};

    return 0;
}