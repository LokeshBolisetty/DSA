#include<iostream>
using namespace std;
#define int long long 
int GCD(int a,int b){
    if(b==0)return a;
    return GCD(b,a%b);
}
  bool canMeasureWater(int x, int y, int z) {
        if(z == 0 || z == x + y) return true;
        if(z > x + y) return false;
        if(x == 0) return z == y;
        if(y == 0) return z == x;
        if(x == y) return z == x;
        int y_in = (y > x)? y : x;
        int x_in = (y > x)? x : y;
        int r = y_in % x_in;
        if (r == 0)
        {
            return z % x_in == 0;
        }else{
            return z % GCD(r, x_in) == 0;
        }
    }
signed main(){
    int N;
    cin>>N;
    while(N--){
        int G1,G2,T;
        cin>>G1>>G2>>T;
        int g;
        if(G2==0 || G1==0) g= G1+G2;
        else g = GCD(G1,G2);
        if(T%g==0)cout<<"Possible"<<endl;
        else cout<<"Not Possible"<<endl;
        //aG1+bG2=T
    }
}