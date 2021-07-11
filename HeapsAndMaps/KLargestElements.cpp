#include<iostream>
#include<vector>
#include <queue>
using namespace std;
vector<int> KLargestElements(vector<int> A,int k){
    priority_queue<int> pq;
    if(k==0 || A.size()==0)return {};
    for(int i=0;i<A.size();i++){
        if(pq.size()<k)pq.push(-A[i]);
        else{
            if(-pq.top()<A[i]){
                pq.pop();
                pq.push(-A[i]);
            }
        }
    }
    vector<int> answer(k);
    int i = 0;
    while(!pq.empty()){
        answer[i]=(-pq.top());
        i++;
        pq.pop();
    }
    return answer;
}
int main(){
    vector<int> A = {1,4,3,2,7,6,5,8,10};
    vector<int> K = KLargestElements(A,4);
    for(int i=0;i<K.size();i++){
        cout<<K[i]<<" ";
    }cout<<endl;
}
