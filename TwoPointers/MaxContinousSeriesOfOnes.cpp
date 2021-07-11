#include <bits/stdc++.h>
using namespace std;
vector<int> MaxContinousSeriesOfOnes(vector<int> A, int B){
    //We make sure that the window we chose always has atmost B zeros
    //Then we compare the lengths of the windows and take maximum size of the window
    int ws=0; //Window start
    int we=0; //Window end
    int zc=0; //Zero count
    int n = A.size();
    int maxLen = INT_MIN;
    int start=0,end=0; //Start and end indices of the maximum window
    for(;we<n;we++){ //With window start as zero, we initialize window end to zero and move further until we reach at most B zeros
        if(A[we]==0)zc++; 
        while(zc>B){ //If we get more than B zeros, 
            if(A[ws]==0)zc--; // we move the starting pointer until we get at max B zeros
            ws++;
        }
        int length = we-ws+1; //Now we measure the length of the window we got(which has atmost B zeros)
        if(length>maxLen){ //If length we got is more than the maxLen we reached upto now then we update the values
            maxLen = length;
            start = ws;
            end=we;
        }
    }
    vector<int> answer; //Since they asked the indices of the windows and not just the length we add the indices to a vector and return it.
    for(int i=start;i<=end;i++){
        answer.push_back(i);
    }
    return answer;
}
int main(){
    vector<int> A = {1,1,0,1,1,0,0,1,1,1};
    int B = 1;
    vector<int> answer = MaxContinousSeriesOfOnes(A,B);
    for(int i=0;i<answer.size();i++)cout<<answer[i]<<" ";
    cout<<endl;
    return 0;
}