#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> RepeatAndMissingElement(vector<int> A){
    //With O(1) space O(n) time and modifying the array
    long long int n  = A.size();
    int repeat;
    long long int count = (n*(n+1))/2;
    for(long long int i =0;i<n;i++){
        if((A[abs(A[i])-1]>0)){
            A[abs(A[i])-1] *= -1;
            count -= abs(A[abs(A[i])-1]);
        }else{
            repeat = abs(A[i]);
        }
    }
    return {repeat,int(count)};
}
vector<int> WithoutChangingTheArray(const vector<int> A){
    //O(1) space O(n) time and no modification to source vector
    int i;
    int n = A.size();
    long long int a,b,c;
    long long int tot, stot;
    long long int sum=0;
    long long int ssum=0;
    vector<int> answer(2,0);
    
    tot = (long long int) n*(n+1)/2;
    stot =(long long int) n*(2*n+1)*(n+1)/6;
    for(i=0;i<n;i++){
        sum += A[i];
        ssum += (long long int) A[i]*A[i];
    }
    
    a = sum-tot;    // x - y
    b = ssum-stot;  // x2 - y2
    c = b/a;        // x + y
    
    answer[0] = (a+c)/2;
    answer[1] = c-answer[0];
    return answer;
}
int main(){
    vector<int> A = {3,1,2,5,3};
    cout<<RepeatAndMissingElement(A)[0]<<" "<<RepeatAndMissingElement(A)[1]<<endl;
}