/*
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]
he largest rectangle is shown in the shaded area, which has area = 10 unit.

Find the area of largest rectangle in the histogram.
Input Format
The only argument given is the integer array A.

Output Format
Return the area of largest rectangle in the histogram.

For Example
Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int nextSmallest(vector<int> &A) {
    vector<int> v = A;
    stack<pair<int,int>> s;
    int n = v.size();
    vector<pair<int,int>> answer(v.size(),{-1,n-1});
    //Finding the nearest minimum element on the right
    s.push({v[0],0});
    for(int i =1;i<n;i++){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first>v[i]){
            answer[s.top().second] = {v[i],i-1};
            s.pop();
        }
        s.push({v[i],i});
    }
    while (s.empty() == false)
    {
        s.pop();
    }
    int max = INT_MIN;
    vector<pair<int,int>> answer2(n,{-1,0});
    //Finding the nearest smallest element on the left
    s.push({v[n-1],n-1});
    for(int i =n-2;i>=0;i--){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first>v[i]){
            answer2[s.top().second] = {v[i],i+1};
            s.pop();
        }
        s.push({v[i],i});
    }
    while (s.empty() == false)
    {
        s.pop();
    }
    //Now find the area of rectangle for each bar in the histogram. Area is formed between the nearest smallest neighbor on the left and the 
    //nearest smallest neighbor on the right. 
    for(int i =0;i<n;i++){
        int area2 = v[i]*(answer[i].second-answer2[i].second+1);
        if(area2>max)max = area2;
    }
    return max;
}
int maxAreaInHistogram(vector<int> &A){
    /*
        Basically you dont have to find the min on left once and min on right once
        when you pop out an element from the stack, the element that you popped out right now has its 
        right min element as the current element(A[i])
        ans left min as the element at the top of stack after popping. (Or zero if the stack is empty)
    */
    stack<pair<int,int>> s;
    int maxArea = 0;
    for(int i =0;i<A.size();i++){
        while(!s.empty() && s.top().first>A[i]){
            pair<int,int> current = s.top();
            int currentElement = current.first;
            int currentIndex = current.second;
            s.pop();
            int area = currentElement*(s.empty()?i:i-s.top().second-1);
            if(area>maxArea)maxArea = area;
        }
        s.push({A[i],i});
    }
    while(!s.empty()){
        pair<int,int> current = s.top();
        s.pop();
        int area = current.first*(s.empty()?A.size():A.size()-s.top().second-1);
        if(area>maxArea)maxArea=area;
    }
    return maxArea;
}

int main()
{
	vector<int> arr = {90,58,69,70,82,100,13,57,47,18};
	int n = sizeof(arr) / sizeof(arr[0]);
    cout<<nextSmallest(arr);
	return 0;
}