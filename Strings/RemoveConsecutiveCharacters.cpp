#include<bits/stdc++.h>
using namespace std;
//Given a string A and integer B, remove all consecutive same characters that have length exactly B.
//Be careful interviewbit gives answer to 
// aaaabbc 2 
// as aaaac
string RemoveConsecutiveCharacters(string A,int B){
    int n = A.size();
    int i = 0;
    string answer = "";
    int start=0,end=0;
    while(start<n){
        end=start;
        while(end<n && A[end]==A[end+1]){
            end++;
        }
        if(end-start+1!=B)answer+=A.substr(start,end-start+1);
        start = end+1;
    }
    return answer;
}
int main(){
    string A = "aabbbbccd";
    int B = 2;
    cout<<RemoveConsecutiveCharacters(A,B)<<endl;
    return 0;
}