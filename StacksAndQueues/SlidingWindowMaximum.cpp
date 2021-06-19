#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> MaximumSlidingWindow(vector<int> A,int B){
    int n  = A.size();
    vector<int> answer;
    deque<int> q(B);//This deque of size k will always be sorted due to the algorithn. 
    //Put all the smaller elements on the back and larger elements on the front
    for(int i =0;i<B;i++){ //Adding all the numbers in the first window
        while(!q.empty() && A[q.back()]<=A[i])q.pop_back();
        q.push_back(i);
    }
    //For all other numbers after the first window
    for(int i =B;i<n;i++){
        answer.push_back(A[q.front()]); //Storing the answer for each window
        while(!q.empty() && q.front()<=i-B)q.pop_front(); //Remove all the elements which do not correspond to current window. 
        // We are removing from the front so that the value we are priting right now is never from a different window. Since this is done for every window
        // we will never print value which is not in the current window. 
        while(!q.empty() && A[q.back()]<=A[i])q.pop_back(); //If a number we encounered now is larger than some numbers in the queue, then remove all of them. 
        // We are printing the largest number in the window so if we encounter a larger number on the right then we no longer need smaller numbers of the left. 
        q.push_back(i);
        
    }
    //Pushing the maximum of last window. 
    answer.push_back(A[q.front()]);
    return answer;
}
int main(){
    vector<int> v = {1,-1};
    int k = 1;
    int n = v.size();
    vector<int> answer = MaximumSlidingWindow(v,k);
    for(int i =0;i<n-k+1;i++){
        cout<<answer[i]<<"\t";
    }cout<<endl;
    return 0;
}