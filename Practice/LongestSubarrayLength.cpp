#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int ls(vector<int> &A){
    unordered_map<int,int> m;
    int preSum = 0;
    int answer = 1;
    for(int i=0;i<A.size();i++){
        if(A[i]==0)preSum-=1;
        else preSum+=1;
        if(m.find(preSum)==m.end())m[preSum] = i;
        if(preSum==1)answer = max(answer,i+1);
        if(m.find(preSum-1)!=m.end()){
            answer = max(answer, i - m[preSum-1]);
        }
    }
    return answer;
}

int main(){
    vector<int> v = { 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    cout<<ls(v)<<endl;
    return 0;
}