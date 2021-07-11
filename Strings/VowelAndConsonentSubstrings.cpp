#include<iostream>
#include<vector>
using namespace std;
/*
Given a string A consisting of lowercase characters.

You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.

Return the count of substring modulo 109 + 7.
*/
bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' ||c=='o' ||c=='u')return true;
    return false;
}
int VowelAndConsonentSubstrings(string A){
    #define MOD 1000000007
    int n = A.size();
    vector<int> v(n);
    char c = tolower(A[0]);
    if(isVowel(c))v[0]=1;
    else v[0]=0;
    for(int i=1;i<n;i++){
        v[i]=v[i-1]+isVowel(tolower(A[i]));
    }
    int t = v[n-1];
    long long int answer = 0;
    for(int i=0;i<n;i++){
        int remaining = n-i-1; 
        int vowels = t-v[i];
        int consonents = remaining -vowels;
        if(isVowel(A[i])){
            answer += consonents;
            answer = answer%MOD;
        }else{
            answer += vowels;
            answer = answer%MOD;
        }
    }
    answer = answer%MOD;
    return answer;
}
int main(){
    string A="abaab";
    cout<<VowelAndConsonentSubstrings(A)<<endl;
}