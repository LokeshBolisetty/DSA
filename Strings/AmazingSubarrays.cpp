#include<iostream>
#include<vector>
using namespace std;

/*
    You are given a string S, and you have to find all the amazing substrings of S.

    Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
*/

bool isVowel(char c){
    c = tolower(c);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
    return false;
}

int AmazingSubarrays(string A){
    int n = A.size();
    long long int answer=0;
    for(int i=0;i<n;i++){
        if(isVowel(A[i])){
            answer+=(n-i);
            answer = answer%10003;
        }
    }
    return answer%10003;
}

int main(){
    string s = "ABEC";
    cout<<AmazingSubarrays(s)<<endl;
    return 0;
}