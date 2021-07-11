#include<bits/stdc++.h>
using namespace std;
int calculate(int a, int b, int c){
    int maxi = max(abs(a-b),abs(b-c));
    return max(maxi,abs(a-c));
}
int minThree(int a,int b,int c){
    int mini = min(a,b);
    return min(mini,c);
}
int Minimize(const vector<int> &A,const vector<int> &B,const vector<int> &C){
    int i=0,j=0,k=0;
    int minimum = calculate(A[0],B[0],C[0]);
    while(i<A.size() && j<B.size() && k<C.size()){
        int r = minThree(A[i],B[j],C[k]);
        if(A[i]==r && i<A.size()-1)i++;
        else if(B[j]==r && j<B.size()-1)j++;
        else if(C[k]==r && k<C.size()-1)k++;
        else break;
        int calc = calculate(A[i],B[j],C[k]);
        minimum = min(calc,minimum);
    }
    return minimum;
}
int main(){
    vector<int> A = {1,4,10};
    vector<int> B = {2,15,20};
    vector<int> C = {10,12};
    cout<<Minimize(A,B,C)<<endl;
    return 0;
}