/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/

#include<iostream>
#include<vector> 
#include<queue>
#include<stack>
using namespace std;


//This passed all the testcases but is only better than 7% of all the submissions. 
string removeKdigits(string num,int k){
    //We dont need to remove consecutive elements.
    //So we just remove the element that adds most value
    //We start checkinf from the left. If the element next to it is smaller, then you remove the current element
    //That way, you will decrease the value of the number. 
    //You will continue this process for atmost k times. 
    //If you still have more numbers left, remove required number of elements from the right. 
    if(num.size()==k)return "0";
    stack<char> s;
    int i = 0;
    while(k>0 && i<num.size()){
        while(!s.empty() && k>0 && s.top()>num[i]){
            s.pop();
            k--;
        }
        s.push(num[i]);
        i++;
    }
    while(i<num.size()){
        s.push(num[i]);
        i++;
    }
    //If the number is in increasing order like 1234 and you want to remove 2 elements you should remove it from the last
    //They wont be removed in the earlier case.
    while(k>0){
        s.pop();
        k--;
    }
    //Remove the leading zeros
    string answer = "";
    while(!s.empty()){
        answer=s.top()+answer;
        s.pop();
    }
    i=0;
    int p = 0;
    while(i<answer.size() && answer[i]=='0'){
        p++;
        i++;
    }
    return p==answer.size()?"0":answer.substr(p);
}

int main(){
    string num = "10200";
    int k = 3;
    cout<<removeKdigits(num,k)<<endl;
    return 0;
}