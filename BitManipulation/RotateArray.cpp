#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void right_rotate_by_one(int arr[], int n)
{

/* Shift operation to the right */
int temp = arr[n - 1], i;
for (i = n - 1; i > 0; i--)
arr[i] = arr[i - 1];
arr[0] = temp;
}
void array_right_rotate(int arr[], int no_of_rotations, int n)
{
for (int i = 0; i < no_of_rotations; i++)
right_rotate_by_one(arr, n);     // Function is called for no_of_rotations times 
for(int i=0;i<n;i++)cout<<arr[i]<<" ";
cout<<endl;
}
int main(){
    int n,k;
    cin>>n>>k;
    int v[n];
    for(int i=0;i<n;i++){
        int t;cin>>t;
        v[i] = t;
    }
    array_right_rotate(v,k,n);
}