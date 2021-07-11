#include<iostream>
#include<vector>
using namespace std;
//Everything here is from editorial

string leftJustify(vector<string> &words,int diff,int i,int j){
    /*We need to calculate spaces on right which is equal to 
    character left - (j-i-1) which gives the space between the
    words */
    int spacesOnRight= diff - (j-i-1);
    //Initialize the current string
    string result=words[i];
    //Then add rest of string seperated by single space
    for(int k=i+1;k<j;k++){
        result+=" ";
        result.append(words[k]);
    }
    string ans="";
    for(int m=0;m<spacesOnRight;m++){
          result+=" ";
      }
    return result;
}

string middleJustify(vector<string> &words,int diff,int i,int j){
    //(j-i-1) which gives the space between the words
    int spacesNeeded = j - i - 1;
    
    //To evenly distribute spaces between words
    int spaces = diff/spacesNeeded;
    
    //Extra spaces which are to be appended at left
    int extraSpaces = diff % spacesNeeded;
    //Initialize the current string
    string result=words[i];
    for(int k=i+1;k<j;k++){
      int spacesToApply = spaces + (extraSpaces-- >0 ? 1 : 0);
      for(int m=0;m<spacesToApply;m++){
          result+=" ";
      }
      result.append(words[k]);  
    }
    return result;
}
vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    //There are two pointers i and j. j is one step ahead of i.
    int i=0,n=words.size();
        while(i < n){
            int j = i+1;
            //Stores the length of word upto the point i points
            int lineLength=words[i].size();
            //Move j pointer forward upto the point where no of characters is greater than maxwidth
            //(j-i+1) gives the no of words and (j-i) gives the space between the words. Since we are doing <maxWidth we have to do j-i-1
            while(j<n && (lineLength + words[j].length() + (j-i-1)<maxWidth)){
                //lineLength only calculates the word character length
                lineLength +=words[j].length();
                ++j;
            }
            int diff = maxWidth - lineLength;
            int numberOfWords = j - i;
            if( numberOfWords == 1 || j>=n){
                res.push_back(leftJustify(words,diff,i,j));
            }else{
                res.push_back(middleJustify(words,diff,i,j));
            }
            //20184165
            //Before j the character length of words can be accomodated in a line 
            i=j;
        }
    return res;
}


int main(){
    vector<string> v = {"What", "must", "be", "shall", "be."};
    int L = 12;
    vector<string> answer = fullJustify(v,L);
    for(int i=0;i<answer.size();i++)cout<<answer[i]<<endl;
    return 0;
}