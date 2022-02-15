/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    //We make a graph where each string is in a node connected to all those nodes
    //which differ from its neighbours only by one letter. 
    queue<pair<string,int>> q;
    unordered_map<string,vector<string>> m;

    //Make a visited map
    unordered_map<string,bool> visited;

    //Populating the map for making the graph
    for(int i=0;i<wordList.size();i++){
        visited[wordList[i]] = false;
        string temp = wordList[i];
        for(int j=0;j<temp.size();j++){
            temp[j] = '*';
            m[temp].push_back(wordList[i]);
            temp = wordList[i];
        }
    }
    

    //Now the problem is equivalent to finding the shortest path between beginWord and endWord nodes
    q.push(make_pair(beginWord,1));
    while(!q.empty()){
        string temp = q.front().first;
        int level = q.front().second;
        if(temp==endWord)return level;
        q.pop();
        string p = temp;
        for(int i=0;i<temp.size();i++){
            p[i] = '*';
            if(m.find(p)!=m.end()){
                for(auto x:m[p]){
                    if(!visited[x]){
                        q.push(make_pair(x,level+1));
                        visited[x] = true;
                    }
                }
            }
            p = temp;
        }
    }
    return 0;
}

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    cout<<ladderLength(beginWord,endWord,wordList)<<endl;
    return 0;
}