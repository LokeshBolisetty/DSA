#include<iostream>
#include<vector>
using namespace std;
int strStr(const string haystack,const string needle){
    if(haystack=="" || needle=="")return -1;
    int n = haystack.size();
    int m = needle.size();
    if(n<m)return -1;
    if(n==m){
        if(haystack==needle)return 0;
        return -1;
    }
    for(int i=0;i<n-m+1;i++){ 
        if(haystack[i]==' ')return -1;  
        if(needle[0]==haystack[i]){
            int end = i+1;
            int j = 1,start=i; 
            while(end<n && j<m && haystack[end]==needle[j]){
                j++;
                end++;
            }
            if(j==m)return start;
        }
    }
    return -1;
}
int main(){
    string haystack = "GoodboyisLokesh";
    string needle = "Good";
    cout<<strStr(haystack,needle)<<endl;
    return 0;
}