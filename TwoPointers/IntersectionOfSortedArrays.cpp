#include<bits/stdc++.h>
using namespace std;
vector<int> IntersectionOfSortedArrays(vector<int> &A,vector<int> &B){
    //This works well. But can be better. This uses O(A.size()) space and (A.size()+B.size()) time
    unordered_map<int,int> m;
    vector<int> answer;
    for(int i=0;i<A.size();i++){
        m[A[i]]++;
    }for(int i=0;i<B.size();i++){
        if(m[B[i]]>0){
            answer.push_back(B[i]);
            m[B[i]]--;
        }
    }
    return answer;
}

vector<int> Efficient(vector<int> &A, vector<int> &B){
    //This is the interviewBit editorial.
    //This uses O(n+m) time and constant space
    vector<int> temp;
    int i=0,j=0;
    int n1=A.size();
    int n2=B.size();
    while(i<n1 && j<n2){
        if(A[i] == B[j]){
            temp.push_back(A[i]);
            i++;
            j++;
        }else if(A[i] < B[j]){
            i++;
        }else{
            j++;
        }
    }
    return temp;
}
int main(){

    return 0;
}