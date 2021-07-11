#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool Hotel(vector<int> arrival,vector<int> departure,int k){
    int n = arrival.size();
    vector<pair<int, int> > ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(make_pair(arrival[i], 1));
		ans.push_back(make_pair(departure[i], 0));
	}
	sort(ans.begin(), ans.end());

	int curr_active = 0, max_active = 0;

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].second == 1) {
			curr_active++;
			max_active = max(max_active,curr_active);
		}
		else
			curr_active--;
	}
	return (k >= max_active);
}
bool HotelBookinsPossible(vector<int> arrive,vector<int> depart,int K){
    int n = arrive.size();
    vector<pair<int,int>> answer;
    for(int i =0;i<n;i++){
        answer.push_back(make_pair(arrive[i],1));
        answer.push_back(make_pair(depart[i],0));
    }
    sort(answer.begin(),answer.end());
    int count=0,maxActive=0;
    for(int i =0;i<answer.size();i++){
        if(answer[i].second==1){
            count++;
            maxActive=max(maxActive,count);
        }else count--;
    }
    return K>=maxActive;
}
int main(){ 
    vector<int> arrive = {40,18};
    vector<int> depart = {40,43};
    int C = 16;
    cout<<HotelBookinsPossible(arrive,depart,C)<<endl;
    return 0;
}