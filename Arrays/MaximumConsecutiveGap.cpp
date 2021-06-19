#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Doesn't work
void radixSort(vector<int> &arr,int max) {
    int n = arr.size();
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}
int MaximumConsecutiveGap(vector<int> A){
    int maxi = *max(A.begin(),A.end());
    int n = A.size();
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< maxi; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = A[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(A[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            A[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
    for(int i =0;i<A.size();i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    int sum=INT_MIN;
    for(int i =1;i<A.size();i++){
        if(A[i]-A[i-1]>sum)sum=A[i]-A[i-1];
    }
    return sum;
}
int main(){
    vector<int> A = {1,10,5};
    cout<<MaximumConsecutiveGap(A)<<endl;
    return 0;
}