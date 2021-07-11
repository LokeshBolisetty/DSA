#include<iostream>
using namespace std;
int LengthOfLastWord(const string A){
    if(A=="")return 0;
    int n = A.size();
    int i=n-1;
    int size=0;
    while(i>=0 && A[i]==' ')i--;
    while(i>=0 && A[i]!=' '){
        i--;
        size++;
    }
    return size;
}
int main(){
    string s = "Hello World   ";
    cout<<LengthOfLastWord(s)<<endl;
    return 0;
}