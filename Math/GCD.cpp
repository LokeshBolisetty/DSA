#include <iostream> 
#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
    if(b==0)return a;
    return GCD(b,a%b);
}
int main(){
    int a=10,b=5;
    cout<<GCD(a,b)<<endl;
    return 0;
}