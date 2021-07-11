#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int count = 1,cooper=0;
    while(count!=0){
        count+=41;
        if(count>=100){
            count-=100;
            cooper+=100;
        }
    }
    cout<<cooper<<endl;
    return 0;
}