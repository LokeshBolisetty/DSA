#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int PairsWithGivenXor(vector<int> A, int B){
    int count=0;
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
       m.insert({A[i],i});
    }
    for(int i=0;i<A.size();i++){
        if(m.find(B^A[i])!=m.end()){
            if(m[B^A[i]]<i)
                count++;
        }
    }
    return count;
}

int main(){
    vector<int> A = {17, 18, 8, 13, 15, 7, 11, 5, 4, 9, 12, 6, 10, 14, 16, 3 };
    int B = 9;
    cout<<PairsWithGivenXor(A,B)<<endl;
    return 0;
}