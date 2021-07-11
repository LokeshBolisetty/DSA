#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int diffkPossible(const vector<int> &A, int B){
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
        m.insert({A[i],i});
    }
    for(int i =0;i<A.size();i++){
        auto it = m.find(A[i]-B);
        if(it==m.end())continue;
        if(it->second!=i)return 1;
    }
    return 0;
}

int main(){
    vector<int> A = {70,48,90};
    int B = 70;
    cout<<diffkPossible(A,B)<<endl;
    return 0;
}