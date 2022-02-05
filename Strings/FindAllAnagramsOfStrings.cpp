/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
using namespace std;

bool isAnagram(string a,string b){
    sort(a.begin(),a.end());
    return (a==b);
}

bool isAnagramLinear(string a, string b){
    //This also gives time limit exceeded
    vector<int> alphabet(26,0);
    for(int i=0;i<a.size();i++){
        alphabet[a[i]-'a']++;
    }
    for(int i=0;i<b.size();i++){
        if(alphabet[b[i]-'a']<=0)return false;
        alphabet[b[i]-'a']--;
    }
    return true;
}

vector<int> findAllAnagramsOfString(string &s, string &p){
    //Time Limit exceeds
    if(p.size()>s.size())return {};
    vector<int> answer;
    //sort(p.begin(),p.end()); //Not needed for isAnagramLinear
    for(int i=0;i<s.size()-p.size()+1;i++){
        if(isAnagramLinear(s.substr(i,p.size()),p))answer.push_back(i);
    }
    return answer;
}

bool areSame(vector<int> &sArr,vector<int> &pArr){
    for(int i=0;i<sArr.size();i++){
        if(sArr[i]!=pArr[i])return false;
    }
    return true;
}

vector<int> findAllAnagramsOfStringArray(string &s,string &p){
    //This works
    if(p.size()>s.size())return {};
    vector<int> pArr(26,0),sArr(26,0);
    for(int i=0;i<p.size();i++){
        pArr[p[i]-'a']++;
    }
    vector<int> answer;
    for(int i=0;i<s.size();i++){
        sArr[s[i]-'a']++;
        if(i+1>=p.size()){
            if(areSame(sArr,pArr))answer.push_back(i-p.size()+1);
            sArr[s[i+1-p.size()]-'a']--;
        }
    }
    return answer;
}

int main(){
    string s = "abab";
    string p = "ab";
    vector<int> answer = findAllAnagramsOfStringArray(s,p);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"\t";
    }
    cout<<endl;
    return 0;
}