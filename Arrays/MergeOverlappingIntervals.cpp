#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval() : start(0),end(0){}
    Interval(int s,int e) : start(s),end(e){}
};
bool customCompare(const Interval &a,const Interval &b){
    //when u return 1, for(a<b) , a will be before b in the sorted order
    if(a.start<b.start)return 1;
    else if (a.start>b.start)return 0;
    if(a.end<b.end)return 1;
    return 0;
}
vector<Interval> MergeOverlappingIntervals(vector<Interval> A){
    sort(A.begin(),A.end(),customCompare);
    vector<Interval> answer;
    for(int i =0;i<A.size();i++){
        Interval a(A[i].start,A[i].end);
        while(i<A.size()-1 && a.end>=A[i+1].start){
            if(A[i+1].end>a.end)a.end = A[i+1].end;
            i++;
        }
        answer.push_back(a);
    }
    return answer;
}
int main(){
    vector<Interval> A = { Interval(4, 100), Interval(48, 94), Interval(16, 21), Interval(58, 71), Interval(36, 53), Interval(49, 68), Interval(18, 42), Interval(37, 90), Interval(68, 75), Interval(6, 57), Interval(25, 78), Interval(58, 79), Interval(18, 29), Interval(69, 94), Interval(5, 31), Interval(10, 87), Interval(21, 35), Interval(1, 32), Interval(7, 24), Interval(17, 85), Interval(30, 95), Interval(5, 63), Interval(1, 17), Interval(67, 100), Interval(53, 55), Interval(30, 63), Interval(7, 76), Interval(33, 51), Interval(62, 68), Interval(78, 83), Interval(12, 24), Interval(31, 73), Interval(64, 74), Interval(33, 40), Interval(51, 63), Interval(17, 31), Interval(14, 29), Interval(9, 15), Interval(39, 70), Interval(13, 67), Interval(27, 100), Interval(10, 71), Interval(18, 47), Interval(48, 79), Interval(70, 73), Interval(44, 59), Interval(68, 78), Interval(24, 67), Interval(32, 70), Interval(29, 94), Interval(45, 90), Interval(10, 76), Interval(12, 28), Interval(31, 78), Interval(9, 44), Interval(29, 83), Interval(21, 35), Interval(46, 93), Interval(66, 83), Interval(21, 72), Interval(29, 37), Interval(6, 11), Interval(56, 87), Interval(10, 26), Interval(11, 12), Interval(15, 88), Interval(3, 13), Interval(56, 70), Interval(40, 73), Interval(25, 62), Interval(63, 73), Interval(47, 74), Interval(8, 36)};
    //vector<Interval> A = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)};
    vector<Interval> B  = MergeOverlappingIntervals(A);
    for(int i =0;i<B.size();i++){
        cout<<'['<<B[i].start<<','<<B[i].end<<']'<<" ";
    }cout<<endl;
    return 0;
}