/*
    Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
    is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

    Note: You can choose more than 2 numbers.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSumAdjacentElements2D(vector<vector<int>> &A){
    int m = A.size(); //Which is always 2 according to the question
    int n = A[0].size();

    //Including the first column
    int inc = max(A[0][0],A[1][0]);

    //Excluding the first column
    int exc = 0;

    for(int i=1;i<n;i++){
        //New value by excluding the ith column.
        //If you exclude the current column, the max value you could hvae is 
        //the maximum of including and excluding the previous column
        int exc_new = max(exc,inc);

        //New value by including ith column.
        //If you include the current column, you must not include previous column
        //Value by excluding prev column(exc) + max value in this column
        inc = exc+max(A[0][i],A[1][i]);

        //Update the value of exc
        exc = exc_new;
    }

    //Return the maximum value - whichever is greater among
    //including and excluding the last column
    return max(inc,exc);
}

int main(){
    vector<vector<int>> A = {{1,2,3,4},
                             {2,3,4,5}};
    cout<<MaxSumAdjacentElements2D(A)<<endl;
    return 0;
}