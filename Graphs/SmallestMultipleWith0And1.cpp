//You are given an integer n, write a program to find the smallest multiple of n which consists of digits 0 and 1 only.
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int MOD(string &S,int N){
    int rem = 0;
    for(int i=0;i<S.size();i++){
        rem = 10*rem + (S[i]-'0');
        rem = rem%N;
    }
    return rem;
}
string findSmallestMultiple(int A){
    /*
    queue<string> q;
    q.push("1");
    set<int> visitedRemainders;
    while(!q.empty()){
        string s = q.front();
        q.pop();
        int rem = MOD(s,A);
        if(rem==0)return s;
        if(visitedRemainders.find(rem)==visitedRemainders.end()){
            visitedRemainders.insert(rem);
            q.push(s+'0');
            q.push(s+'1');
        }
    }
    return "-1";*/
    queue<long long int> q;
    q.push(1);
    set<long long int> visitedRemainders;
    while(!q.empty()){
        long long int s = q.front();
        q.pop();
        long long int rem = s%A;
        if(rem==0)return to_string(s);
        if(visitedRemainders.find(rem)==visitedRemainders.end()){
            visitedRemainders.insert(rem);
            q.push(rem*10);
            q.push(rem*10+1);
        }
    }
    return "-1";
}
string editorial(int N){
        if(N==1) return "1";
    vector<int> p(N,-1);//parent state
    vector<int> s(N,-1);//step from parent to current
    //BFS
    int steps[2] = {0,1};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==0) break;
        for(int step: steps){
            int next = (curr*10+step)%N;
            if(p[next]==-1){
                p[next]=curr;
                s[next]=step;
                q.push(next);
            }
        }
    }
    //build reversed string
    string number;
    for(int it=0; it!=1; it=p[it])
        number.push_back('0'+s[it]);
    number.push_back('1');
    //return the reverse if it
    return string(number.rbegin(), number.rend());
}
signed main(){
    int N = 14;
    cout<<findSmallestMultiple(N)<<endl;
    return 0;
}