#include<iostream>
#include <vector>
using namespace std;
vector<string> PrettyJSON(string A){
    int n = A.size();
    vector<string> answer;
    int tabCount=0;
    for(int i=0;i<n;i++){
        char c= A[i];
        bool flag = false;
        switch (c)
        {
            case '{':
            {
                flag = true;
                string s;
                for(int i=0;i<tabCount;i++)s.push_back('\t');
                tabCount++;
                s.push_back('{');
                answer.push_back(s);
                break;
            }
            case '[':
            {
                flag = true;
                string s;
                for(int i=0;i<tabCount;i++)s.push_back('\t');
                tabCount++;
                s.push_back('[');
                answer.push_back(s);
                break;
            }
            case ']':
            {
                flag = true;
                tabCount--;
                string s;
                for(int i=0;i<tabCount;i++)s.push_back('\t');
                s.push_back(']');
                if(i<n-1 && A[i+1]==','){
                    s.push_back(',');
                    i++;
                }
                answer.push_back(s);
                break;
            }
            case '}':
            {
                flag = true;
                tabCount--;
                string s;
                for(int i=0;i<tabCount;i++)s.push_back('\t');
                s.push_back('}');
                if(i<n-1 && A[i+1]==','){
                    s.push_back(',');
                    i++;
                }
                answer.push_back(s);
                break;
            }
            default:
                break;
        }
        if(flag)continue;
        string k;
        for(int j=0;j<tabCount;j++){
            k.push_back('\t');
        }
        while(i<n){
            if(A[i]=='}'||A[i]=='{'||A[i]=='['||A[i]==']'){
                i--;
                break;
            }
            k+=A[i];
            if(A[i]==',')break;
            i++;
        }
        answer.push_back(k);
    }
    return answer;
}
int main(){
    //string A = "{\"attributes\":[{\"nm\":\"ACCOUNT\",\"lv\":[{\"v\":{\"Id\":null,\"State\":null},\"vt\":\"java.util.Map\",\"cn\":1}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":13585},{\"nm\":\"PROFILE\",\"lv\":[{\"v\":{\"Party\":null,\"Ads\":null},\"vt\":\"java.util.Map\",\"cn\":2}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":41962}]}";
    string A = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";
    vector<string> a = PrettyJSON(A);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}