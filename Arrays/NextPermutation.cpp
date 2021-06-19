#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
mplement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

Input 1:
    A = [1, 2, 3]

Output 1:
    [1, 3, 2]

Input 2:
    A = [3, 2, 1]

Output 2:
    [1, 2, 3]

Input 3:
    A = [1, 1, 5]

Output 3:
    [1, 5, 1]

Input 4:
    A = [20, 50, 113]

Output 4:
    [20, 113, 50]

*/
vector<int> NextPermutation(vector<int> &A){
    //Traverse from right to left and see the number which is not in descending order. 
    //The suffix which gets affected is in a descending order before the change.
    //For example 1 2 3 -> 1 3 2 suffix i 3
    //1 2 3 6 5 4  -> 1 2 4 3 5 6 // Suffix being 6 5 4 in this case. 
    //Find the first number that violates this property(of being in descending order)
    //Swap it with the nearest(smallest I think) greater number. Note that even now the suffix is in descending order. 
    //Reverse this suffix to get the answer. 
    int size=A.size(),i=size-2;
    while(i>=0 && A[i]>=A[i+1])--i;
    if(i<0){
        sort(A.begin(),A.end());
        return A;
    }else{
        int l =i+1 ,r =size-1,target  = A[i]; 
        int idx =-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(A[mid]<=target)
                r = mid-1;
            else{
                l = mid+1;
                if(idx==-1 || A[idx]>=A[mid])
                    idx = mid;
            }
        }
        int temp = A[i];
        A[i] = A[idx];
        A[idx] = temp;
        reverse(A.begin()+i+1,A.end()); 
    }
    return A;
}
int main(){
    vector<int> v = {2,1,8,7,6,5};
    NextPermutation(v);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}