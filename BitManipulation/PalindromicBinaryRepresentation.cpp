#include<iostream>
#include<queue>
using namespace std;
int getValue(string s){
    int n = s.size();
    int answer = 0;
    for(int i=n-1;i>=0;i--){
        answer = answer*2 + (s[i]-'0');
    }
    return answer;
}
int PalindromicBinaryRepresentation(int A){
    //The structure of these palindromes happens to be a tree
    //              11
    //          101     111
    //        1001       1111
    //    10101 10001  11011  11111
    //Doint a BFS n-1 upto n times will give u the nth palindrome. (1st palindrome is 1)
    if(A==1)return A;
    queue<string> q;
    q.push("11");
    A--;
    while(!q.empty()){
        string k = q.front();
        q.pop();
        A--;
        if(!A){
            return getValue(k);
        }else{
            int mid = k.size()/2;
            if(k.size()%2==0){
                string s0=k,s1=k;
                s0.insert(mid,"0");
                s1.insert(mid,"1");
                q.push(s0);
                q.push(s1);
            }else{
                string s0=k;
                string p(1,k[mid]);
                s0.insert(mid,p);
                q.push(s0);
            }
        }
    }
    return 0;
}
int main(){
    int A = 9;
    cout<<PalindromicBinaryRepresentation(A)<<endl;
    return 0;
}