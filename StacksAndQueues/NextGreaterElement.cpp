#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    vector<int> v = A;
    stack<pair<long long,long long>> s;
    unordered_map<long long,long long> mp;
    long long n = v.size();
    s.push({v[n-1],n-1});
    // Greater element on the left
    for(long long i =n-2;i>0;i--){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first<v[i]){
            mp[s.top().second] = i;
            s.pop();
        }
        s.push({v[i],i});
    }
    //greater element on the right
    stack<pair<long long,long long>> s2;
    unordered_map<long long,long long> mp2;
    s2.push({v[0],0});
    for(long long i =1;i<n;i++){
        if(s2.empty()){
            s2.push({v[i],i});
            continue;
        }
        while(!s2.empty() && s2.top().first<v[i]){
            mp2[s2.top().second] = i;
            s2.pop();
        }
        s2.push({v[i],i});
    }
    long long max = LLONG_MIN;
    int a,b;
    for(long long i =0;i<n;i++){
        long long r = mp[i]*mp2[i];
        if(mp[i]*mp2[i]>max){
            max = mp[i]*mp2[i];
        }
    }
    return (max%1000000007);
}
int main()
{
	vector<int> arr = {  5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<solve(arr);
	return 0;
}
