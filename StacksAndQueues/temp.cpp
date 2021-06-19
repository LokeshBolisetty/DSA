#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void greaterRight(vector<int> v){
    stack<int> s;
    unordered_map<int,int> mp2;
    s.push(v[0]);
    int n = v.size();
    for(int i =1;i<n;i++){
        if(s.empty()){
            s.push(v[i]);
            continue;
        }
        while(!s.empty() && s.top()<v[i]){
            mp2[s.top()] = v[i];
            s.pop();
        }
        s.push(v[i]);
    }
    for (int i = 0; i < n; i++)
    cout << v[i] << " ---> "
        << mp2[v[i]] << endl;
}
int solve(vector<int> &A) {
    vector<int> v = A;
    stack<int> s;
    unordered_map<int,int> mp;
    int n = v.size();
    s.push(v[n-1]);
    for(int i =n-2;i>0;i--){
        if(s.empty()){
            s.push(v[i]);
            continue;
        }
        while(!s.empty() && s.top()<v[i]){
            mp[s.top()] = v[i];
            s.pop();
        }
        s.push(v[i]);
    }
    stack<int> s2;
    unordered_map<int,int> mp2;
    s2.push(v[0]);
    for(int i =1;i<n;i++){
        if(s2.empty()){
            s2.push(v[i]);
            continue;
        }
        while(!s2.empty() && s2.top()<v[i]){
            mp2[s2.top()] = v[i];
            s2.pop();
        }
        s2.push(v[i]);
    }
    int max = INT_MIN;
    for(int i =0;i<n;i++){
        if(mp[v[i]]*mp2[v[i]]>max)max = mp[v[i]]*mp2[v[i]];
    }
    for (int i = 0; i < n; i++)
		cout << v[i] << " ---> "
			<< mp[v[i]] << endl;

            for (int i = 0; i < n; i++)
		cout << v[i] << " ---> "
			<< mp2[v[i]] << endl;
    return max;
}

void greaterLeft(vector<int> v){
    stack<int> s;
    unordered_map<int,int> mp;
    int n = v.size();
    s.push(v[n-1]);
    for(int i =n-2;i>0;i--){
        if(s.empty()){
            s.push(v[i]);
            continue;
        }
        while(!s.empty() && s.top()<v[i]){
            mp[s.top()] = v[i];
            s.pop();
        }
        s.push(v[i]);
    }
    for (int i = 0; i < n; i++)
    cout << v[i] << " ---> "
        << mp[v[i]] << endl;
    
}
vector<int> lesser(vector<int> v){
    stack<pair<int,int>> s;
    vector<int> g;
    vector<int> answer(v.size(),-1);
    unordered_map<int,int> mp;
    
    int n = v.size();
    s.push({v[n-1],n-1});
    for(int i =n-2;i>=0;i--){
        if(s.empty()){
            s.push({v[i],i});
            continue;
        }
        while(!s.empty() && s.top().first>v[i]){
            answer[s.top().second] = v[i];
            //mp[s.top().first] = v[i];
            s.pop();
        }
        s.push({v[i],i});
    }
    while (s.empty() == false)
	{
		//mp[s.top()] = -1;
        answer[s.top().second] =-1;
		s.pop();
	}
    for (int i = 0; i < n; i++)
    cout << v[i] << " ---> "
        << answer[i] << endl;
    return answer;
}
void printNGE(int arr[], int n)
{
	stack<int> s;
	unordered_map<int, int> mp;

	/* push the first element to stack */
	s.push(arr[0]);

	// iterate for rest of the elements
	for (int i = 1; i < n; i++)
	{
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}

		/* if stack is not empty, then
		pop an element from stack.
		If the popped element is smaller
		than next, then
		a) print the pair
		b) keep popping while elements are
		smaller and stack is not empty */
		while (s.empty() == false
			&& s.top() < arr[i])
		{
			mp[s.top()] = arr[i];
			s.pop();
		}

		/* push nex
        t to stack so that we can find
		next smaller for it */
		s.push(arr[i]);
	}

	/* After iterating over the loop, the remaining
	elements in stack do not have the next smaller
	element, so print -1 for them */
	while (s.empty() == false)
	{
		mp[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ---> "
			<< mp[arr[i]] << endl;
}

// Driver Code
int main()
{
	vector<int> arr = { 3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	lesser(arr);
	return 0;
}
