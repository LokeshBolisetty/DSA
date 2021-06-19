#include<bits/stdc++.h>
using namespace std;
int ContainerWithMostWater(vector<int> &A){
    int i=0,j=A.size()-1;
    int mx=j*min(A[i],A[j]);
    while(i<j)
    {
        if((j-i)*min(A[j],A[i]) > mx)
        mx=(j-i)*min(A[j],A[i]);
        if(A[i]<A[j])
            i++;
        else j--;
    }
    return mx;
}
int main(){
    vector<int> A = {1,4,10};
    vector<int> B = {2,15,20};
    vector<int> C = {10,12};
    return 0;
}