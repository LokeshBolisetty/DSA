/*
You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Ways(int A){
    vector<int> v(A,0);
    if(A==0)return 1;
    v[0]=1;
    v[1]=2;
    for(int i=2;i<A;i++){
        //You can reach i from either i-1 or i-2
        //Do not do the following
        //v[i+1]+=v[i]
        //v[i+2]+=v[i]
        //Because doing this adds the same number multiple times
        v[i]=v[i-1]+v[i-2];
    }
    return v[A-1];
}

int main(){
    int A =10;
    cout<<Ways(A)<<endl;
    return 0;
}