#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string LargestCommonPrefix(vector<string> A){   
    int n = A.size();
    if(n==1)return A[0];
    if(n==0)return "";
    for(int j=0;;j++){
        char c = A[0][j];
        for(int i=1;i<n;i++){
            if(A[i].size()>j && A[i][j]!=c)return A[i].substr(0,j);
            if(A[i].size()<=j)return A[i];
        }
    }
}
string Editorial(vector<string> A){
     string s;
    //sorting the strings lexicographically 
    sort(A.begin(),A.end());
    int m,n;
    m=A.size()-1;
    n=min(A[0].length(),A[m].length());
    int i=0;
    //first and last string will be most dissimilar thus finding common charcters in these
    while(i<n && A[0][i]==A[m][i])
    {
        s+=A[0][i];
        i++;
    }
    return s;
}
int main(){
    vector<string> A = {"ABCD"};
    cout<<Editorial(A)<<endl;
    return 0;
}