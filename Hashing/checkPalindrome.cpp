/*
Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.
*/
int Solution::solve(string A) {
    int n=A.size(),i=0,j=n-1;
    if(n==1)return 1;
    bool removed = false;
    while(i<n && j>=0 && i<j){ //Happens only upto i<j not i<=j because for strings like aba we can remove b and its taken care of in the 22nd line
        if(A[i]!=A[j] && !removed){
            if(A[i]==A[j-1]){
                j--;
                removed = true; //For strings of the type ggd since g!=d we move pointer from d to g
            }else if(A[i+1]==A[j]){
                i++;
                removed = true; //For strings of the type gdd since g!=d, we move pointer from g to d
            }else return 0;
        }
        else return 0; //If alread one character is removed and we are still not able to get a palindrome return 0
        i++;j--; //Updating i and j always
    }
    if(i==j)return 1; //For aba kind of strings if i=j=1 we can delete b. So return 1
    if(removed)return 1; //Otherwise if we have already removed one character from the string then return true
    return 0;//else not possible
}

//Elegant and working code
bool checkPalindrome(string s){
    if(s.size()<=1)return true;
    unordered_map<char,int> m;
    int count = 0;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
        if(m[s[i]]&1)count++;
        else count--;
        cout<<count<<endl;
    }
    if(count<=1)return true;
    else return false;
}
