#include<iostream>
using namespace std;
void solver(string s,int st,int B,string &maxString){
    if(B==0){
        return;
    }
    for(int i=st;i<s.size()-B;i++){
        for(int j=i+1;j<s.size();j++){
            if(s[j]<s[i])continue;
            swap(s[i],s[j]);
            if(s>maxString)maxString = s;
            solver(s,st+1,B-1,maxString);
            swap(s[i],s[j]);
            
        }
    }
    return;
}
string MaximalString(string s,int B){
    string maxString = s;
    solver(s,0,B,maxString);
    return maxString;
}
int main(){
    string A = "254";
    int B = 2;
    cout<<MaximalString(A,B)<<endl;
    return 0;
}