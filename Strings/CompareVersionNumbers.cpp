#include<iostream>
using namespace std;
int Editorial(string A,string B){
    if(A.size() == 0 && B.size() == 0) return 0;
    if(A == B) return 0; // not required but ok.
    string x = A, y = B;
    string s1 = "", s2 = "";
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '.') {
            x = A.substr(0, i);
            s1 = A.substr(i + 1, A.size() - i - 1);
            break;
        }
    }
    for(int i = 0; i < B.size(); i++) {
        if(B[i] == '.') {
            y = B.substr(0, i);
            s2 = B.substr(i + 1, B.size() - i - 1);
            break;
        }
    }
    string s = "";
    if(x.size() > y.size()) {
        for(int i = 0; i < x.size() - y.size(); i++) s.push_back('0');
        y = s + y;//Adding zeros in the start so that we can directly do x<y etc instead of manually comaparing the numeric strings
    }
    if(x.size() < y.size()) {
        for(int i = 0; i < y.size() - x.size(); i++) s.push_back('0');
        x = s + x;
    }
    if(x > y) return 1;
    if(y > x) return -1;
    return Editorial(s1, s2);
}

string retrieve(string A){
    int n=A.size(),i=0;
    int j=0;
    while(i<n && A[i]!='.'){
        i++;
    }
    string s = A.substr(0,i);
    if(s=="0")return s;
    else{
        i = 0;
        while(s[i]=='0')i++;
    }
    string k = s.substr(i);
    return k;
}

int compareVersionNumbers(string A, string B){
    //Did not get suggest as editorial. Better use the editorial
    int n=A.size(),m=B.size(),i=0,j=0;
    string a = retrieve(A);
    string b = retrieve(B);

    while(i<n && j<m){
        i += a.size()+1;
        j += b.size()+1;
        // n-=A.size()+1;
        // m-=B.size()+1;
        if(a!=b){
            if(a.size()!=b.size())return a.size()>b.size()?1:-1;
            else{
                int p=0;
                while(p<a.size() && a[p]==b[p])p++;
                if(p==n)return 0;
                else{
                    if(a[p]-'0'>b[p]-'0')return 1;
                    else return -1;
                }
            }
        }
        else{
            bool flag = false;
            if(i<n)a = retrieve(A.substr(i));
            else {a="0";flag=true;}
            if(j<m)b= retrieve(B.substr(j));
            else {b="0";flag=true;}
            if(flag)break;
        }
    }
    if(a.size()!=b.size())return a.size()>b.size()?1:-1;
    else{
        int p=0;
        int k = a.size();
        while(p<a.size() && a[p]==b[p])p++;
        if(p==k)return 0;
        else{
            if(a[p]-'0'>b[p]-'0')return 1;
            else return -1;
        }
    }
}
int main(){
    string A = "444444444444444444444444";
    string B = "5";
    cout<<Editorial(A,B)<<endl;
    return 0;
}