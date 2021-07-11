#include<iostream>
#include<vector>
using namespace std;
int SingleNumber(vector<int> A){
    int x=A[0];
    int n = A.size();
    for(int i=1;i<n;i++){
        x = x^A[i];
    }
    return x;
}
int main(){
    vector<int> A = {1,2,2,3,1};
    cout<<SingleNumber(A)<<endl;
    return 0;
}