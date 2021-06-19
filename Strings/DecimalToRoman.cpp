#include<iostream>
using namespace std;
/*
SYMBOL       VALUE
I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900 
M             1000 
*/
string DecimalToRoman(int A){
    string answer = "";
    while(A>0){
        if(A>=1000){
            int count=A/1000;
            for(int i=0;i<count;i++){
                answer+='M';
            }
            A-=count*1000;
        }
        if(A>=900 && A<1000){
            answer+="CM";
            A-=900;
        }if(A>=500){
            answer+='D';
            A-=500;
        }if(A>=400){
            answer+="CD";
            A-=400;
        }
        if(A>=100){
            int count=A/100;
            for(int i=0;i<count;i++){
                answer+='C';
            }
            A-=count*100;
        }if(A>=90){
            answer+="XC";
            A-=90;
        }if(A>=50){
            answer+="L";
            A-=50;
        }if(A>=40){
            answer+="XL";
            A-=40;
        }if(A>=10){
            int count=A/10;
            for(int i=0;i<count;i++){
                answer+='X';
            }
            A-=count*10;
        }if(A>=9){
            answer+="IX";
            A-=9;
        }if(A>=5){
            int count=A/5;
            for(int i=0;i<count;i++){
                answer+='V';
            }
            A-=count*5;
        }if(A>=4){
            answer+="IV";
            A-=4;
        }if(A>=1){
            int count=A;
            for(int i=0;i<count;i++){
                answer+='I';
            }
            A-=count;
        }
    }
    return answer;
}
int main(){
    int A = 2021;
    cout<<DecimalToRoman(A)<<endl;
    return 0;
}