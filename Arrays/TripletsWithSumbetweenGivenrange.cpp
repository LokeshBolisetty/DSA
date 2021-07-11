#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define min 7
#define max 8
int TripletsInRange(vector<string> A){
    int n = A.size();
    vector<float> B;
    for(int i =0;i<n;i++){
        B.push_back(stof(A[i]));
    }
    float a = B[0],b=B[1],c=B[2];
    for(int i =3;i<n;i++){
        float sum=a+b+c;
        if(sum>min && sum<max)return 1;
        else{
            if(sum>max){
                if(a>b && a>c){
                    a=B[i];
                }else if(b>a && b>c){
                    b=B[i];
                }else c=B[i];
            }else{
                if(a<b && a<c)a=B[i];
                else if(b<c && b<a)b=B[i];
                else c=B[i];
            }
        }
    }
    if(a+b+c<max && a+b+c>min)return 1;
    else return 0;
}
int main(){
    vector<string> A = {"2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191"};
    cout<<TripletsInRange(A)<<endl;
    return 0;
}