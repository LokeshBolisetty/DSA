#include<iostream>
using namespace std;
bool isEven(string A){
    int n = A.size()-1;
    if(A.size()>0)if(A[n]=='0'||A[n]=='2'||A[n]=='4'||A[n]=='6'||A[n]=='8')return 1;
    return 0;
}
string DivideBy2(string A){
    int carry=0;
    string answer="";
    int n = A.size();
    for(int i=0;i<n;i++){
        int val = carry*10 + A[i]-'0';
        if(val>1 || answer.size()){//Just to aviod leading zeros
            char c = char(val/2+'0');
            answer.push_back(c);
        }
        carry=val%2;//If the character you just encountered is odd, then add 1 to carry
        //Note:While dividing with 2, carry can be only 1 or 0
    }
    return answer;
}
int PowerOf2(string A){
    if(A==""||A=="1")return 0;
    string val = DivideBy2(A);
    while(val!="1"){
        val = DivideBy2(val);
        //cout<<val<<endl;
        if(!isEven(val) && val!="1")return 0;
    }   
    return 1;
}
int main(){
    string A = "64";
    cout<<PowerOf2(A)<<endl;
}


/*
string DivideBy2(string A){
    int n = A.size();
    string answer="";
    bool flag = false;
    int c = 0;
    for(int i=0;i<n;i++){
        if(A[i]>='2'||A[i]=='0'){
            string p;
            p+=A[i];
            if(isEven(p) && !flag){
                answer.push_back(((A[i]-'0')/2)+'0'); 
                flag = false;
            }
            else{
                answer.push_back(((A[i]-'0')/2)+'0');
                A[i]='1';
                if(flag)A[i]+=c;
                i--;
                flag = true;
            }
        }else{
            string k;k += A[i];
            k+=A[i+1];
            answer.push_back(stoi(k)/2+'0');
            i++;
        }   
    }
    return answer;
}
*/