#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string LargestNumber(vector<int> A){
    vector<string> v;
    for(int i =0;i<A.size();i++){
        v.push_back(to_string(A[i]));
    }
    sort(v.begin(),v.end());
    string s="";
    for(int i =0;i<v.size();i++){
        s=v[i]+s;
    }
    return s;
}
int main(){
    vector<int> A = {3,30,34,5,9};
    cout<<LargestNumber(A);
    return 0;
}