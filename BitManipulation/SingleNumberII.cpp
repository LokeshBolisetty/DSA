#include<vector>
#include<set>
#include<iostream>
using namespace std;
/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?
*/
int SingleNumberII(const vector<int> &A){
    /*
    Let us look at every bit position.

    Every number that occurs thrice will either contribute 3 ‘1’s or 3 ‘0’s to the position.

    The number that occurs once X will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.

    So:

    If X has 1 in that position, we will have (3x+1) number of 1s in that position.
    If X has 0 in that position, we will have (3x+1) number of 0s in that position.

    */
    int answer=0,p=1,n=A.size();
    for(int i=0;i<32;i++){
        int odd=0;
        for(int j=0;j<n;j++){
            int x=p&A[j];
            if(x)odd++;
        }
        if(odd%3!=0)answer+=p;
        p=p<<1;
    }
    return answer;
}
int main(){
    vector<int> A = {1,2,4,3,3,2,2,3,1,1};
    cout<<SingleNumberII(A)<<endl;
    return 0;
}