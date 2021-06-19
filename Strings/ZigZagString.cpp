#include<iostream>
using namespace std;
string ZigZagString(string A,int B){
    if(B==1)return A;
    int n = A.size();
    string arr[B];
    int row=0;
    bool down=true;
    for(int i=0;i<n;i++){
        arr[row].push_back(A[i]);
        if(row==B-1)down = false;
        else if(row==0)down=true;
        if(down)row++;
        else row--;        
    }
    string answer;
    for(int i=0;i<B;i++){
        answer+=arr[i];
    }
    return answer;
}
int main(){
    string k = "PAYPALISHIRING";
    cout<<ZigZagString(k,6)<<endl;
    return 0;
}






// string ZigZagString(string A,int B){
//     //Doesnt work
//     string answer ="";
//     int n = A.size();
//     if(B==1)return A;
//     // P0    I6     N12
//     // A1  L5 S7  I11 G13
//     // Y2 A4   H8 R10
//     // P3       I9
//     // (0 6 12)            (1 5 7 11 13)          (2 4 8 10)                     (3 9)
//     // Add n+2   Add n and 2 alreternatively    Add 2 and n alternatively      Add n+2

//     //P0             H8       
//     //  A1         S7  I9     
//     //    Y2     I6      R10   
//     //     P3  L5           I11   G13
//     //      A4                 N12
//     //(0 8) (1 7 9) (2 6 10) (3 5 11 13) (4 12)
//     int r =B/2;
//     if(2*r<B)r++;
//     int factor = 2*(B);
//     for(int i=1;i<=r;i++){
//         int idx = i-1;
//         // if(i==1)factor = 2*(B-1);
//         // else if(i==r)factor=2*(r);
//         // else factor = 2*(B-i+1);
//         factor -=2;
//         bool flag = true;
//         while(idx<n){
//             answer += A[idx];
//             if(i==1)idx+=factor;
//             else if(i==r && B%2==1)idx+=factor;
//             else{
//                 if(flag)idx+=factor;
//                 else idx+=2*(B-1);
//                 flag = !flag;
//             }
//         }
//     }
//     int f = -1;
//     for(int i=r+1;i<=B;i++){
//         if(factor<=2)f=1;
//         int idx = i-1;
//         factor+=f*2;
//         // int factor;
//         // if(i==B)factor = 2*(B-1);
//         // else factor = 2*(B-2);
//         bool flag = true;
//         while(idx<n){
//             answer+=A[idx];
//             if(i==B)idx+=factor;
//             else{
//                 if(flag)idx+=2*(B-2);
//                 else idx+=factor;
//                 flag = !flag;
//             }
//         }
//     }
//     return answer;
// }