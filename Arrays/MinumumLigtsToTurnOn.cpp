#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].

Initially all lights are off.

Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.
*/
int MinimumLightsToTurnOn(vector<int> A, int B){
    int count=0;
    int n = A.size();
    for(int i =0;i<n;i++){
        int next = i+B-1;
        int idx = next;
        int prev = max(0,i-B+1);
        bool flag=true;
        while(idx>=prev){
            if(A[idx]){
                count++;
                i=idx+B-1;
                flag=false;
                break;
            }
            idx--;
        }
        if(flag)return -1;
    }
    return count;
}
int main(){
    vector<int> A = { 0, 0, 1, 1, 1, 0, 0, 1};
    int B = 3;
    cout<<MinimumLightsToTurnOn(A,B)<<endl;
}