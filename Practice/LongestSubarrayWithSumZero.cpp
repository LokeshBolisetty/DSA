#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
vector<int> lszero(vector<int> &A){
    int preSum = 0;
    int glow = -1,ghigh = -1;
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0;i<A.size();i++){
        preSum += A[i];
        if(m.count(preSum)==0)
            m[preSum] = i;
        else{
            int low =m[preSum]+1;
            int high = i;
            int size = high -low + 1;
            if(glow == -1 || size > ghigh-glow+1){
                glow = low;
                ghigh = high;
            }
            count+=m[preSum];
        }
        if(preSum==0){
            int low = 0;
            int high = i;
            if(glow==-1 || ghigh - glow + 1 < i+1){
                glow = low;
                ghigh = high;
            }
            count++;
        }
    }
    //return vector from index glow to ghigh
    vector<int> res;
    if(glow==-1)return res;
    for(int i=glow;i<=ghigh;i++)
        res.push_back(A[i]);
    return res;
}
int main(){
    vector<int> v = {0,-19, 8, 2, -8, 19, 5, -2, -23};
    vector<int> answer = lszero(v);
    //print the contents of answer
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<" ";
    cout<<endl;
    return 0;
}