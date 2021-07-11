#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> MaximumSumCombinations(vector<int> A,vector<int> B,int C){
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++){
            int temp = A[i]+B[j];
            if(pq.size()<C)pq.push(temp);
            else{
                if(pq.top()<temp){
                    pq.pop();
                    pq.push(temp);
                }else
                    break;
            }
        }
    }
    vector<int> answer(C);
    int i=C-1;
    while(!pq.empty()){
        answer[i]=pq.top();
        i--;
        pq.pop();
    }
    return answer;
}
int main(){
    vector<int> A = {1,4,2,3};
    vector<int> B = {2,5,1,6};
    int C = 4;
    vector<int> a = MaximumSumCombinations(A,B,C);
    for(auto x:a){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}