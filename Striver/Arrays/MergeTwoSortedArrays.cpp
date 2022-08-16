#include <vector> 
#include<iostream>
using namespace std;
void insert(vector<int> &arr, int idx, int element){
    if(arr[idx]!=0)
    for(int i=arr.size()-1; i>idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = element;
    return;
}
//Gives TLE as the insertion operation takes O(n) time. 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i = 0, j=0;
    while(i<m && j<n){
        if(arr1[i]==0 || arr1[i]>arr2[j]){
            insert(arr1, i, arr2[j]);
            j++;
            m++;
        }
        i++;
    }
    while(j<n){
        arr1[i] = arr2[j];
        i++;j++;
    }
    return arr1;
}

//Works
vector<int> sorter(vector<int> &arr1, vector<int> &arr2, int m, int n){
    int i = m-1, j=n-1,idx = m+n-1;
    while(i>=0 && j>=0){
        if(arr1[i]>arr2[j]){
            arr1[idx] = arr1[i];
            i--;
        }else{
            arr1[idx] = arr2[j];
            j--;
        }
        idx--;
    }
    while(j>=0){
        arr1[idx] = arr2[j];
        idx--;
        j--;
    }
    return arr1;
}

int main(){
    vector<int> arr1 = {3,4,6,0,0};
    vector<int> arr2 = {1, 8, 10};
    sorter(arr1, arr2, 3, 3);
    for(int x:arr1)cout<<x<<" ";cout<<endl;
    return 0;
}