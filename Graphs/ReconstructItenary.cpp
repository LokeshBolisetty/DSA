/*

Question:
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

    For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

*/

#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void DFS(vector<string> &answer,unordered_map<string, priority_queue<string,vector<string>,greater<string>>> &m,string source){
    while(!m[source].empty()){
        string dest = m[source].top();
        m[source].pop();
        DFS(answer,m,dest);
    }
    answer.push_back(source);
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    //Generate the graph
    unordered_map<string, priority_queue<string,vector<string>,greater<string>>> m;
    for (int i = 0; i < tickets.size(); i++)
    {
        m[tickets[i][0]].push(tickets[i][1]);
    }
    vector<string> answer;
    DFS(answer,m,"JFK");
    reverse(answer.begin(),answer.end());
    return answer;
}

unordered_map<string, multiset<string>> maptickets;
void dfs(vector<string> &result, string source)
{
    while (!maptickets[source].empty())
    {
        string dest = *maptickets[source].begin();            //declaring iterator for finding dest
        maptickets[source].erase(maptickets[source].begin()); //deleting after travelling
        dfs(result, dest);
    }
    result.push_back(source); //pushing into result
}

vector<string> findItinerary2(vector<vector<string>> &tickets)
{

    for(int i =0;i<tickets.size();i++){
        maptickets[tickets[i][0]].insert(tickets[i][1]);
    }
    vector<string> result;
    dfs(result, "JFK");                    //starting from JFK
    reverse(result.begin(), result.end()); //result is created during return time of recursion thus reverse needed
    return result;                         //returning result
}

int main()
{
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> answer = findItinerary(tickets);
    for (auto place : answer)
        cout << place << " ";
    cout << endl;
    return 0;
}