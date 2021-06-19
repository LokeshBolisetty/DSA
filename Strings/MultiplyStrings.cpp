#include<iostream>
#include<vector>
using namespace std;
//These dont work for negative numbers
string MultiplyOwn(string A,string B){
    int n1 = A.size(),n2=B.size();
    string res(n1+n2,'0');
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            int num = (A[i]-'0')*(B[j]-'0')+res[i+j+1]-'0';
            res[i+j+1]  = num%10+'0';
            res[i+j] +=num/10;
        }
    }
    //To remove leading zeros
    for(int i=0;i<res.size();i++){
        if(res[i]!='0')return res.substr(i);
    }
    return "0";
}
//  36
// x12
// _____
//  72
// 36x
// _____
// 432

//Borrowed from https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
string Multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0) return 0;
    if(num1=="0"||num2=="0")return 0;
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;
         
        // Go from right to left in num2            
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}
int main(){
    string A = "1636549684574684864";
    string B = "205487478549874887";
    cout<<Multiply(A,B)<<endl;
    return 0;
}