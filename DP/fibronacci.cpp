#include<iostream>
#include<vector>
using namespace std;
vector<int> fib(int n){
    vector<int> v(n+1,0);
    v[1]=1;
    for(int i=0;i<n;i++){
        v[i+1]+=v[i];
        v[i+2]+=v[i];
    }
    return v;
}
int main(){
    int n = 10;
    vector<int> v = fib(10);
    for(int i=1;i<n+1;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}