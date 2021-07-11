#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//NOT SOLVED
int main(){
    int n;
    cin>>n;
    int arr[n];
    bool leftFound=  false,rightFound = false;
    for(int i =0;i<n;i++){
        cin>>arr[i];
        if(i>0 && !leftFound){
            if(arr[i]<arr[i-1]){
                //L = i;
                leftFound = true;
            }
        }
        if(i>0 && !rightFound){
            if(arr[i]<arr[i-1]){
            
            }
        }
    }
    return 0;
}