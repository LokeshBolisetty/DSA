#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MaximumAbsoluteDifference(vector<int> A)
{
    /*
    int max1=INT_MIN,min1=INT_MAX,max2=INT_MIN,min2=INT_MAX;
    int n = A.size();
    for(int i =0;i<n;i++){
        max1 = max(max1,A[i]+i);
        max2 = max(max2,A[i]-i);
        min1 = min(min1,A[i]+i);
        min2 = min(min2,A[i]-i);
    }
    return max(max1-min1,max2-min2);
    */

    //Kadane's algorithm
    int n = A.size();
    vector<int> diff;
    for (int i = 1; i < n; i++)
    {
        diff.push_back(A[i - 1] - A[i]);
    }
    int best = 1, curr = 0;
    int len = 1;
    for (int i = 0; i < n - 1; i++)
    {
        curr = curr + diff[i] + 1;
        best = max(best, curr);
        if (curr < 0)
        {
            curr = 0;
            len = 1;
        }
        else
        {
            len++;
        }
    }
    //cout<<"best is "<<best<<endl;
    for (int i = 0; i < n - 1; i++)
        diff[i] = diff[i] * -1;
    len = 1;
    curr = 0;
    for (int i = 0; i < n - 1; i++)
    {
        curr = curr + diff[i] + 1;
        // cout<<"curr is "<<curr<<endl;
        best = max(best, curr);
        if (curr < 0)
        {
            curr = 0;
            len = 1;
        }
        else
        {
            len++;
        }
    }
    //cout<<"best is "<<best<<endl;
    return best;

//The approach below takes O(n^2) time
// int n = A.size();
// int sum,maxSum=INT_MIN;
// for(int i =0;i<n;i++){
//     for(int j=i;j<n;j++){
//         sum=abs(A[i]-A[j])+abs(i-j);
//         if(sum>maxSum)maxSum = sum;
//     }
// }
// return maxSum;
}
int main()
{
    vector<int> A = {25,4,1,3};
    cout << MaximumAbsoluteDifference(A) << endl;
    return 0;
}