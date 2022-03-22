/*
You are given a binary string of length N
in one operation you can either remove the substruing "10" or "11" such that the size of the str reduces by 2. 
Find the minimum length of hte string you can obtain by doing the operation any number of times.
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n=str.size();
    int count=0;
    int i=0;
    while(i+1<n){
        if(str[i]=='1' && str[i+1]=='0'){
            str.erase(i,2);
            n=str.size();
            count++;
        }
        else if(str[i]=='1' && str[i+1]=='1'){
            str.erase(i,2);
            n=str.size();
            count++;
        }
        else{
            i++;
        }
    }
    cout<<n<<endl;
    return 0;
}