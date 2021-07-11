#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string solve(string A) {
    queue<char> q;
    vector<int> arr(26,0),rep(26,0);
    string k;
    for(int i =0;i<A.size();i++){
        if(i==0){
            q.push(A[i]);
            arr[A[i]-'a'] = 1;
            k+=q.front();
            continue;
        }
        else{
            if(arr[A[i]-'a']==0){
                q.push(A[i]);
                arr[A[i]-'a']=1;
            }
            else rep[A[i]-'a']=1;
        }
        while(rep[q.front()-'a']==1 && !q.empty()){
            q.pop();
        }
        if(!q.empty())
            k+=q.front();
        else k+='#';
    }
    return k;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}