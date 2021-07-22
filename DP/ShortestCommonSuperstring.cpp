/*
Given a set of n strings arr[], find the smallest string that contains each string in the given set as substring. We may assume that no string in arr[] is substring of another string.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MIN -2147
using namespace std;

pair<string,int> findCommon(string A,string B){
    int max = INT_MIN;
    int m = A.size();
    int n = B.size();
    string common = "";
    // Compare the last i characters in A 
    // with first i characters in B
    for(int i=1;i<=min(m,n);i++){
        if(A.compare(m-i,i,B,0,i)==0){
            // Compares m-i charaters of A starting at i 
            // with atmost i characters of B starting at 0
            // returns zero if they are same
            if(max<i){
                max = i;
                common = A+B.substr(i);
                //Create a string with A and the uncommon part of B
            }
        }
    }
    // Compare the first i characters in A
    // With last i characters of B
    for(int i=1;i<=min(m,n);i++){
        if(A.compare(0,i,B,n-i,i)==0){
            if(max<i){
                max = i;
                common = B+A.substr(i);
            }
        }
    }
    return {common,max};
}


string shortestCommonSuperstring(vector<string> &A){    
    vector<string> temp(A.begin(),A.end());

    while(temp.size()!=1){
        int n = temp.size();
        string common="";
        int max = INT_MIN;
        int l,r;
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                pair<string,int> p = findCommon(temp[i],temp[j]);
                if(p.second>max){
                    max = p.second;
                    common = p.first;
                    l = i,r=j;
                }
            }
        }
        if(max==INT_MIN){
            temp[0]+=temp.back();
        }else{
            temp[l]=common;
            temp[r]=temp.back();
        }
        temp.pop_back();
    }
    return temp[0];
}

int main(){
    vector<string> A = { "fevlutui", "ilxfntf", "whiade", "idehwakceipb", "lkgvxeb"};
    // This program doesnt work for this example "fevlutui", "ilxfntf", "whiade", "idehwakceipb", "lkgvxeb"
    // Here it takes fevlutui first and combines it with ilxfntf but if you take ilxfntf first and add it to fevlutui then you can also add idehwakceipb at the end
    
    cout<<shortestCommonSuperstring(A)<<endl;
    return 0;
}