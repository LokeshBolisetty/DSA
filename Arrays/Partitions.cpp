#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Partitions(int A,vector<int> &B){
    vector<int> prefix(A);
    prefix[0] = B[0];
    unordered_map<int,pair<int,int>> m;
    m[prefix[0]] = {0,1};
    for(int i =1;i<A;i++){
        prefix[i]=prefix[i-1]+B[i];
        m[prefix[i]].first = i;
        m[prefix[i]].second++;
    }
    if(prefix[A-1]%3!=0)return -1;
    int count=0;
    for(int i =0;i<A;i++){
        if(m.find(3*prefix[i])!=m.end() && 
            m.find(2*prefix[i])!=m.end()){
                int maxCount = max(m[prefix[i]].second,m[2*prefix[i]].second);
                maxCount = max(maxCount,m[3*prefix[i]].second);
                count+=maxCount;
        }
    }
    return count;
}
int main(){
    vector<int> A = {0,1,-1,0};
    cout<<Partitions(A.size(),A)<<endl;
    return 0;
}