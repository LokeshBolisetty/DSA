#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
vector<int> MaxPair(vector<int> &A,vector<int> &B){
    int C = A.size();
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
vector<int> Editorial(vector<int> &A, vector<int> &B) {
	priority_queue<pair<int, pair<int, int>>> pq;
    // first int is the value itself, next 2 int are the position of 
    // val's constituent vals in A and B
    set<pair<int, int>> s; //  position of val's constituent vals in A and B
    // used to not allow repeat indices
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    pq.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    // sum of last ele of A and B is largest. Push it
    s.insert(make_pair(n-1, n-1));
    
    vector<int> ans;
    int k = n; // we want only k ie. n elements in ans.
    while(k--){
        pair<int, pair<int, int>> top = pq.top(); pq.pop();
        ans.push_back(top.first); // only the largest value 
        int L = top.second.first; // index of consitutent ele in A
        int R = top.second.second; // same but in B
        
        if(R>0 && L>= 0 && s.find(make_pair(L, R-1)) == s.end()){
            // if this pair has not been created before
            pq.push(make_pair(A[L]+B[R-1], make_pair(L, R-1)));
            s.insert(make_pair(L,R-1));
        }
        if(R>=0 && L>0 && s.find(make_pair(L-1, R)) == s.end()){
            // if this pair has not been created before
            pq.push(make_pair(A[L-1]+B[R], make_pair(L-1, R)));
            s.insert(make_pair(L-1,R));
        }
        
    }
    
    return ans;
}
int main(){
    vector<int> A = {1,4,2,3};
    vector<int> B = {2,5,1,6};
    vector<int> comb = Editorial(A,B); //Not sure if editorial is faster or mine is faster
    for(auto x:comb){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}