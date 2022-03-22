#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string minWindow(string A, string B) {
    unordered_map<char,int> stringg;
    unordered_map<char,int> pattern;
    if(A.size()<B.size())return "";
    for(int i=0;i<B.size();i++){
        pattern[B[i]]++;
    }
    int count = 0;
    int start_idx = -1;
    int start = 0;
    int minLength = INT32_MAX;
    for(int i=0;i<A.size();i++){
        stringg[A[i]]++;
        if(pattern[A[i]]>=stringg[A[i]])count++;
        if(count==B.size()){
            //Window found
            //Now minimize the Window
            while(stringg[A[start]]>pattern[A[start]] || pattern.count(A[start])==0){
                if(stringg[A[start]]>pattern[A[start]])stringg[A[start]]--;
                start++;
            }
            int newLength = i-start+1;
            if(newLength<minLength)
            {
                minLength = newLength;
                start_idx = start;
            }
        }
    }
    if(start_idx==-1)return "";
    return A.substr(start_idx,minLength);
}

int main(){
    string A = "ADOBECODEBANC";
    string B = "ABC";
    cout<<minWindow(A,B)<<endl;
}