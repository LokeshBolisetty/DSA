#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> SmallerLeft(vector<int> v){
    //If there is no smaller element on the left, -1 is given for that value by default. 
    int size = v.size();
    vector<int> element(size,-1);
    vector<int> index(size,-1);
    stack<pair<int,int>> s;
    for(int i =size-1;i>-1;i--){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first>v[i]){
            element[s.top().second] = v[i];
            index[s.top().second] = i;
            s.pop();
        }
        s.push(make_pair(v[i],i));
    }
    return element;
}
vector<int> LargerLeft(vector<int> v){
    //If there is no larger element on the left, -1 is given for that value by default. 
    int size = v.size();
    vector<int> element(size,-1);
    vector<int> index(size,-1);
    stack<pair<int,int>> s;
    for(int i =size-1;i>-1;i--){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first<v[i]){
            element[s.top().second] = v[i];
            index[s.top().second] = i;
            s.pop();
        }
        s.push(make_pair(v[i],i));
    }
    return element;
}

vector<int> LargerRight(vector<int> v){
    //If there is no larger element on the right, -1 is given for that value by default. 
    int size = v.size();
    vector<int> element(size,-1);
    vector<int> index(size,-1);
    stack<pair<int,int>> s;
    for(int i =0;i<size;i++){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first<v[i]){
            element[s.top().second] = v[i];
            index[s.top().second] = i;
            s.pop();
        }
        s.push(make_pair(v[i],i));
    }
    return element;
}

vector<int> SmallerRight(vector<int> v){
    //If there is no smaller element on the left, -1 is given for that value by default. 
    int size = v.size();
    vector<int> element(size,-1);
    vector<int> index(size,-1);
    stack<pair<int,int>> s;
    for(int i =0;i<size;i++){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first>v[i]){
            element[s.top().second] = v[i];
            index[s.top().second] = i;
            s.pop();
        }
        s.push(make_pair(v[i],i));
    }
    return element;
}

int main(){
    vector<int> v = {2,5,3,1,7,2,4,8,10};
    vector<int> answer = SmallerRight(v);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<"-->"<<answer[i]<<endl;
    }
    return 0;
}