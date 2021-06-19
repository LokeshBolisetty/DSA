#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// return max value of j-i such that A[i]<A[j]
int MaximumGap(vector<int> A){

    int n = A.size();
    vector<pair<int,int>> p;
    for(int i =0;i<n;i++){
        p.push_back({A[i],i});
    }
    sort(p.begin(),p.end());
    int answer = 0,min=INT_MAX;
    for(int i =0;i<n;i++){
        min=std::min(min,p[i].second);
        answer = max(answer,p[i].second-min);
    }
    return answer;
}
int main(){
    vector<int> A={3,5,4,2};
    cout<<MaximumGap(A)<<endl;
    return 0;
}