#include<iostream>
#include <vector>
using namespace std;
vector<int> LPS(string A){
    int n = A.size();
    vector<int> prix(n,0);
    for(int i=1;i<n;i++){
        int j = prix[i-1];
        while(j>0 && A[i]!=A[j]){
            j = prix[j-1];
        }
        if(A[i]==A[j])j++;
        prix[i] = j;
    }
    return prix;
}
vector<int> KMP(string A,string B){
    //B is the needle, A is the haystack
    string C = B+'#'+A;
    vector<int> L = LPS(C);
    vector<int> answer;
    for(int i=B.size()+1;i<L.size();i++){
        if(L[i]==B.size() && i-B.size()>=B.size())answer.push_back(i-2*B.size());
    }
    return answer;
}
int main(){
    string A = "AABAACAADAABAABA";
    //LPS  =    01010123420101010101
    string B = "AABA";
    vector<int> lps = LPS(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<A.size();i++){
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    vector<int> p = KMP(A,B);
    for(int i =0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}