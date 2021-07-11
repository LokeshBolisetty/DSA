#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MaxArea(vector<string> A){
    int n=A.size();int m=A[0].size();
    int dp[m][3];//r,g,b 0,1,2
    int top[m][3];//r,g,b;
    for(int i=0;i<m;i++)top[i][0]=0,top[i][1]=0,top[i][2]=0;
    for(int i=0;i<m;i++)
    {
        
        int h1=0;int gup=-1,gdown=-1,rup=-1,rdown=-1,bup=-1,bdown=-1;
        while(h1<n)
        {
         if(A[h1][i]=='r'){rup=h1;break;}
         h1++;
        }
        h1=0;
         while(h1<n)
        {
         if(A[h1][i]=='g'){gup=h1;break;}
         h1++;
        }
        h1=0;
         while(h1<n)
        {
         if(A[h1][i]=='b'){bup=h1;break;}
         h1++;
        }
        
        //////////////
        h1=n-1;
         while(h1>=0)
        {
         if(A[h1][i]=='r'){rdown=h1;break;}
         h1--;
        }
        h1=n-1;
         while(h1>=0)
        {
         if(A[h1][i]=='g'){gdown=h1;break;}
         h1--;
        }
        h1=n-1;
         while(h1>=0)
        {
         if(A[h1][i]=='b'){bdown=h1;break;}
         h1--;
        }
        ///////////////////
        
        
        dp[i][0]=max(abs(gup-bdown),abs(gdown-bup))+1;//r
        
        if(gup==-1||bup==-1)dp[i][0]=0;
        dp[i][1]=max(abs(rup-bdown),abs(rdown-bup))+1;//g
        if(rup==-1||bup==-1)dp[i][1]=0;
        dp[i][2]=max(abs(rup-gdown),abs(rdown-gup))+1;//b
        if(rup==-1||gup==-1)dp[i][2]=0;
        
        if(gup==-1)top[i][1]=-1;
        if(rup==-1)top[i][0]=-1;
        if(bup==-1)top[i][2]=-1;
        
        
        
        
    }
    int rback=-1;int rfront=-1;int gfront=-1,gback=-1,bback=-1,bfront=-1;
    for(int i=m-1;i>=0;i--)
    {
        if(top[i][0]==0){rback=i;break;}
    }
    for(int i=0;i<m;i++)if(top[i][0]==0){rfront=i;break;}
    for(int i=m-1;i>=0;i--)if(top[i][1]==0){gback=i;break;}
     for(int i=0;i<m;i++)if(top[i][1]==0){gfront=i;break;}
      for(int i=m-1;i>=0;i--)if(top[i][2]==0){bback=i;break;}
     for(int i=0;i<m;i++)if(top[i][2]==0){bfront=i;break;}
     
     for(int i=0;i<m;i++)
     {
        
         dp[i][0]=(max(abs(i-rfront),abs(i-rback))+1)*dp[i][0];
         
         dp[i][1]=(max(abs(i-gfront),abs(i-gback))+1)*dp[i][1];
         
         dp[i][2]=(max(abs(i-bfront),abs(i-bback))+1)*dp[i][2];
         
          if(rfront==-1)dp[i][0]=0;
         if(gfront==-1)dp[i][1]=0;
         if(bfront==-1)dp[i][2]=0;
         
     }
     int ans=0;
     for(int i=0;i<m;i++)ans=max(ans,max(dp[i][0],max(dp[i][1],dp[i][2])));
     return ans/2+ans%2;
     
}
int main(){
    vector<string> A =  {"rrrrr","rrrrg","rrrrr","bbbbb"};
    cout<<MaxArea(A)<<endl;
    return 0;
}