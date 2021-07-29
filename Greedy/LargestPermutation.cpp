#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findLargestPermutation(vector<int> &A, int B){
    //The question does not state it but all the testcases have numbers from 1 to A.size()
    int n = A.size();
    vector<int> idx(n);
    for(int i =0;i<n;i++){
        idx[A[i]-1] = i;
    }
    for(int i=0;i<n && B>0;i++){
        if(A[i]==n-i)continue;
        int temp=A[i];
        swap(A[idx[n-i-1]],A[i]);
        swap(idx[n-i-1],idx[temp-1]);
        B--;
    }
    return A;
}
int main()
{
    vector<int> A = {3, 2, 1};
    int B = 2;
    vector<int> C = findLargestPermutation(A, B);
    for (auto i : C)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}