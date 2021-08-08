#include<iostream>
#include<vector>
using namespace std;
/**
 * Modifes A to have 1 in all fibronacci numbers.
 * @param A Vector to be modified
 * Note: The given vector itself gets modified, nothing will be returned
 * */
void fibronacci(vector<int> &A){
    A[0] = 1;
    A[1] = 1;
    A[2] = 1;
    A[3] = 1;
    int a = 2,b=3;
    int i =5;
    while(i<A.size()){
        A[i] = 1;
        int temp = a;
        a = b;
        b += temp;
        i = b;
    }
    return;
}

/**
 * Calculates the number of fibronacchi numbers required to form given number
 * */
int sumOfFibronacciNumbers(int N){
    //Since the question doesn't mention anything, I think fibronacci numbers alone can be used
    //to form any number
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    int i = 2;
    while(fib[i-1]+fib[i-2]<=N){
        fib.push_back(fib[i-1]+fib[i-2]);
        i++;
    }
    i = fib.size()-1;
    int count = 0;
    while(N>0){
        //Use the maximum number as many times as possible to decrease the number as much as possible
        count += N/fib[i];
        //Since our assumption is that any number can be formed using fibronacci numbers
        //We now used the max number as many times as possible. 
        //So we now find the number of steps required to make the remaining number
        //Its greedy approach
        N = N%fib[i];
        i--;
    }
    return count;
}
int main(){
    int A = 42;
    cout<<sumOfFibronacciNumbers(A)<<endl;
    return 0;
}