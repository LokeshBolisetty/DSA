#include<iostream>
using namespace std;
int LengthOfLastWord(string A){
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
int Reverse(string A){
    string answer = "";
    int length = LengthOfLastWord(A);

}
int main(){
    string s = "Hello World   ";
    cout<<LengthOfLastWord(s)<<endl;
    return 0;
}