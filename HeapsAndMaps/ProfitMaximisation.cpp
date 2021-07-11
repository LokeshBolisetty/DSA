#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ProfitMaximisation(vector<int> A,int B){
    priority_queue<int> pq;
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    int answer=0;
    for(int i=0;i<B;i++){
        answer+=pq.top();
        pq.push(pq.top()-1);
        pq.pop();
    }
    return answer;
}

int main(){

    return 0;
}