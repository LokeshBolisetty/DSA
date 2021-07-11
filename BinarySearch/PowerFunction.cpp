#include<iostream>
using namespace std;
int pow(int a,int b,int d){
    if(a==0 && b==0 && d!=0)return 0;
    if(d==1)return 0;
    if(a==0)return 0;
    if(b==0)return 1;
    if(b==1)return a%d<0?a%d+d:a%d;
    long long int answer=1,y=a%d;
    while(b>0){
        if(b&1)answer = (answer*y)%d;
        y = (y*y)%d;
        if(y<0)y+=d;
        b = b>>1;

    }
    return answer;
}
int main(){
    int a =71045970, b= 41535484,d=64735492;
    cout<<pow(a,b,d)<<endl;
    return 0;
}