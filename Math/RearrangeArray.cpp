#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Change Arr[i] into Arr[Arr[i]] with O(1) extra space
void RearrangeArray(vector<int> &A){
    int n = A.size();
    for(int i=0;i<n;i++){
        A[i] = A[i]+(A[A[i]]%n)*n;
    }
    for(int i=0;i<n;i++){
        A[i]/=n;
    }
}
int main(){
    vector<int> v = {1,2,3,0};
    //Answer should be {2,3,0,1}
    RearrangeArray(v);
    for(int i=0;i<4;i++)cout<<v[i]<<"\t";
    cout<<endl;
    return 0;
}