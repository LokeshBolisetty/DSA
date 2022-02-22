/*

Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Returns the number of intervals which are not covered by some other interval
int removeCoveredIntervals(vector<vector<int>>& intervals){
    sort(intervals.begin(),intervals.end());
    //Represents the number of intervals that are not already covered. 
    //There will be atleast one such interval. 
    //So we initialize it with 1
    int count = 1;

    //The position of element with which we compare. 
    //We dont compare the current interval with the just previous interval because of cases like [1,2], [1,4]
    int pos = 0;

    for(int i=1;i<intervals.size();i++){
        //For distinct elements, the both the bounds are greater than the prev interval's bound
        if(intervals[i][0]>intervals[pos][0] && intervals[i][1] > intervals[pos][1])count++;

        //The lower bound can be same in consecutive elements but upper bound has to be different because the elements are already sorted
        //PS: It is given that the intervals are unique. 
        if(intervals[i][1] > intervals[pos][1])pos=i;
    }
    return count;
}


int main(){
    vector<vector<int>> v = {{1,4},{3,6},{2,8}};
    cout<<removeCoveredIntervals(v)<<endl;
    return 0;
}