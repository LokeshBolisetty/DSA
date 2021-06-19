#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> FizzBuzz(int A){
    vector<string>solution;
    for(int i=1;i<=A;i++){
        if(i%3==0 && i%5==0){
            solution.push_back("FizzBuzz");
        }
        else if(i%3==0)
        solution.push_back("Fizz");
        else if(i%5==0)
        solution.push_back("Buzz");
        else
        solution.push_back(to_string(i));
    }
    return solution;
}
int main(){
    int n=20;
    vector<string> s = FizzBuzz(n);
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}