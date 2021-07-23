#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSumAdjacentElements1D(vector<int> &A){
    int n = A.size();

    //Including the first value
    int inc =A[0];

    //Excluding the first value
    int exc = 0;

    for(int i=1;i<n;i++){
        //New value by excluding the ith value.
        //If you exclude the current value, the max value you could hvae is 
        //the maximum of including and excluding the previous value
        int exc_new = max(exc,inc);

        //New value by including ith value.
        //If you include the current value, you must not include previous value
        //Value by excluding prev value(exc) + max value in this value
        inc = exc+A[i];

        //Update the value of exc
        exc = exc_new;
    }

    //Return the maximum value - whichever is greater among
    //including and excluding the last column
    return max(inc,exc);
}

int main(){
    vector<int> A = {1,2,3,4};
    cout<<MaxSumAdjacentElements1D(A)<<endl;
    return 0;
}