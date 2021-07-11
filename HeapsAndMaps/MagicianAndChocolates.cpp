#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int MaxChocolates(int A,vector<int> &B){
    priority_queue<int> pq;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    long long int answer = 0;
    for(int i=0;i<A;i++){
        answer+=pq.top();
        answer%=1000000007;
        pq.push(pq.top()/2);
        pq.pop();
    }
    return answer%1000000007;
}
int main(){
    vector<int> A = {2147483647, 2000000014, 2147483647};
    int maxChoco = MaxChocolates(10,A);
    cout<<maxChoco<<endl;
    return 0;
}