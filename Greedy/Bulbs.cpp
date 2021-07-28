/*
N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.
*/
#include<iostream>
#include<vector>
using namespace std;
int minimumSwitches(vector<int> &A){
    bool reverse = false;
    int count = 0,n=A.size();;
    for(int i=0;i<n;i++){
        if(!reverse){
            if(A[i]==0){
                count++;
                reverse = true;
            }
        }else{
            if(A[i]==1){
                count++;
                reverse = false;
            }
        }
    }
    return count;
}
int main(){
    vector<int> A = {0,1,0,1};
    cout<<minimumSwitches(A)<<endl;
    return 0;
}