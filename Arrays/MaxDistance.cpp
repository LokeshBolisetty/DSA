#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximumGap(const vector<int> &A) {
    if(A.size()==0)return 0;
    vector<pair<int,int>> the;
    for(int i=0;i<A.size();i++){
        the.push_back({A[i],i});
    }
    sort(the.begin(),the.end());
    //Sorting made sure that A[i]<A[j] for all i<j
    //Now we need the maximum of j-i. So we need the maximum of index of element on right - current index
    //So we obviously chose the largest index element on the right. 
    //For that we use suffix array for the indices.
    vector<int> suffix(A.size());
    suffix[A.size()-1] = the[A.size()-1].second;
    int answer = 0;
    for(int i=A.size()-2;i>=0;i--){
        suffix[i] = (suffix[i+1]>the[i].second)?suffix[i+1]:the[i].second;
        answer = max(answer,suffix[i+1]-the[i].second);
    }
    return answer;
}
int main(){
    vector<int> A = {3,2,1};
    cout<<maximumGap(A)<<endl;
    return 0;
}