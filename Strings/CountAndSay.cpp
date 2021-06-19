#include<iostream>
#include<vector>
using namespace std;
/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
string Say(string A){
    int n = A.size();
    string answer="";
    int start=0,end=0;
    for(int i=0;i<n;i++){
        while(end<n-1 && A[end]==A[end+1]){
            end++; //Find how many times a letter repeated
        }
        int repeat = end-start+1;
        answer+=to_string(repeat); //answer has to be appended with repeat+number
        answer+=A[start];
        start = end+1;
        end++;
        i=start-1; //Move i to the next distinct element.
    }
    return answer;
}
string CountAndSay(int A){
//Using BFS
    if(A==1)return "1";
    string answer="11";
    if(A==2)return answer;
    for(int i=3;i<=A;i++){
        answer = Say(answer);
    }
    return answer;
}
int main(){
    int A = 3;
    for(int i=0;i<10;i++)
        cout<<CountAndSay(i)<<endl;
    return 0;
}