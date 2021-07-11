#include<iostream>
#include <vector>
#include<map>
using namespace std;
vector<int> Solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int,string> m;
    for(int i=0;i<A.size();i++){
        if(m.find(A[i])==m.end())m[A[i]]="1";
    }
    for(int i=0;i<B.size();i++){
        if(m.find(B[i])==m.end() || m[B[i]]=="1")m[B[i]]+='2';
    }
    for(int i=0;i<C.size();i++){
        if(m.find(C[i])==m.end() || m[C[i]]=="1" || m[C[i]]=="2" || m[C[i]]=="12")m[C[i]]+='3';
    }
    vector<int> v;
    for(auto x:m){
        //cout<<x.first<<"\t"<<x.second<<endl;
        if(x.second.size()>1)v.push_back(x.first);
    }
    return v;
}

int main(){
    vector<int> A = {1,1,2};
    vector<int> B = {2,3};
    vector<int> C = {3};
    vector<int> v = Solve(A,B,C);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}