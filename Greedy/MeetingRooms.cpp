/*
Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.

Find the minimum number of conference rooms required so that all meetings can be done.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Custom Comparator to sort by the second element of the vector
 * @param A First value to be compared
 * @param B Second value to be compared
 * */
bool custCompare(vector<int> &A,vector<int> &B){
    return A[0]<B[0];
}

int disjointIntervals(vector<vector<int>> &A){
    /*
        Sort the intervals, with respect to their end points.
        Now, traverse through all the intervals, if we get two overlapping intervals, then greedily choose the interval with lower end point since, choosing it will ensure that intervals further can be accommodated without any overlap.
        Apply the same procedure for all the intervals and print all the intervals which satisfy the above criteria.
    */
    sort(A.begin(),A.end(),custCompare);
    for(int i=0;i<A.size();i++){
        cout<<A[i][0]<<" "<<A[i][1]<<endl;
    }
    int n = A.size();
    int count = 1;
    int rightLimit = A[0][1];
    for(int i=1;i<n;i++){
        int rooms = 1;
        bool flag = false;
        while(i<n && rightLimit>A[i][0]){
            rooms++;
            i++;
            flag = true;
        }
        if(flag)i--;
        count = max(count,rooms);
        rightLimit = A[i][1];
    }
    return count;
}
int main(){
    vector<vector<int>> A = {
  {6, 13},
  {5, 15},
  {0, 15},
  {2, 28},
  {20, 25},
  {25, 27}
};
    cout<<disjointIntervals(A)<<endl;
    return 0;
}