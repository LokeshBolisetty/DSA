#include <bits/stdc++.h>
using namespace std;
int MaximumOnesAfterModification(vector<int> &A, int B)
{
    //This is not efficitnt
    //O(n^2) solution
    int n = A.size();
    vector<int> sum(n);
    sum[0] = A[0];
    for (int i = 0; i < n; i++)
    {
        sum[i] = sum[i - 1] + A[i];
    }
    int i = 0, j = 0, maxLen = INT_MIN;
    for (; i < n, j < n; i++, j++)
    {
        int t = B;
        bool flag = true;
        int zc = i + 1;
        while (i < n && j < n && t)
        {
            if (A[j] == 0)
            {
                if (flag)
                {
                    flag = false;
                    zc = j;
                }
                t--;
            }
            j++;
        }
        while (i < n && j < n && A[j])
            j++;
        int length = j - i;
        maxLen = max(length, maxLen);
        i = zc;
        j = i;
    }
    return maxLen;
}
int EfficientMaximumOnes(vector<int> A, int B)
{
    //We make sure that the window we chose always has atmost B zeros
    //Then we compare the lengths of the windows and take maximum size of the window
    int ws=0; //Window start
    int we=0; //Window end
    int zc=0; //Zero count
    int n = A.size();
    int maxLen = INT_MIN;
    for(;we<n;we++){ //With window start as zero, we initialize window end to zero and move further until we reach at most B zeros
        if(A[we]==0)zc++; 
        while(zc>B){ //If we get more than B zeros, 
            if(A[ws]==0)zc--; // we move the starting pointer until we get at max B zeros
            ws++;
        }
        int length = we-ws+1; //Now we measure the length of the window we got(which has atmost B zeros)
        if(length>maxLen){ //If length we got is more than the maxLen we reached upto now then we update the values
            maxLen = length;
        }
    }
    return maxLen;
}
int main()
{
    vector<int> A = {1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    int B = 2;
    cout << EfficientMaximumOnes(A, B) << endl;
    return 0;
}