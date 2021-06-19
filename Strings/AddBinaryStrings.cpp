#include<iostream>
using namespace std;
string AddBinaryStrings(string A,string B){
    int n=A.size(),m=B.size();
    string answer = "";
    int size =min(n,m);
    int i=n-1,j=m-1;
    int carry = 0;
    while(i>=0 && j>=0){
        int sum = A[i]+B[j]+carry-'0'-'0';
        if(sum<2){
            answer=to_string(sum)+answer;
            carry=0;
        }
        else{
            carry=1;
            if(sum==2)answer='0'+answer;
            else if(sum==3)answer='1'+answer;
        }
        i--;j--;
    }
    while(i>=0){
        int sum = A[i]+carry-'0';
        if(sum<2){
            answer=to_string(sum)+answer;
            carry=0;
        }
        else{
            carry=1;
            if(sum==2)answer='0'+answer;
            else if(sum==3)answer='1'+answer;
        }
        i--;
    }
    while(j>=0){
        int sum = B[j]+carry-'0';
        if(sum<2){
            answer=to_string(sum)+answer;
            carry=0;
        }
        else{
            carry=1;
            if(sum==2)answer='0'+answer;
            else if(sum==3)answer='1'+answer;
        }
        j--;
    }
    if(carry)answer='1'+answer;
    return answer;
}
int main(){
    string A = "1110000000010110111010100100111";
    string B =                          "101001";
    //          1110000000010110111010101010000
    //           110000000010110111010101010000
    cout<<AddBinaryStrings(A,B)<<endl;
    return 0;
}