#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string NextSimilarNumber(string s){
    int n=s.size();
    int e=n-2;
    //Traverse from right to left and see the number which is not in descending order. 
    //The suffix which gets affected is in a descending order before the change.
    //For example 1 2 3 -> 1 3 2 suffix i 3
    //1 2 3 6 5 4  -> 1 2 4 3 5 6 // Suffix being 6 5 4 in this case. 
    //Find the first number that violates this property(of being in descending order)
    //Swap it with the smallest greater number. Note that even now the suffix is in descending order. 
    //Reverse this suffix to get the answer.
    for(;e>=0;e--){
        if(s[e]<s[e+1]){
            break;
        }
    }
    if(e<0) return "-1";
    //Find the smallest number greater than s[e] in the suffix
    int l =e+1 ,r =n-1,target  = s[e]; 
        int idx =-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(s[mid]<=target)
                r = mid-1;
            else{
                l = mid+1;
                if(idx==-1 || s[idx]>=s[mid])
                    idx = mid;
            }
        }
    //swap the smallest element in the suffix with the s[e]
    char t = s[e];
    s[e]=s[idx];
    s[idx]=t;
    reverse(s.begin()+e+1,s.end());
    return s;
}
int main(){
    string A  = "215894";
    cout<<NextSimilarNumber(A)<<endl;
    return 0;
}