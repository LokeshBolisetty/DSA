#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define INT_MAX 20000000
using namespace std;

int orangesRottingIdeal(vector<vector<int>> &grid)
{
    //This code has been taken from someone on leetcode. 
    //The trick here is that all inital rotten oranges have been pushed into the queue at first
    //Now if there are three rotten oranges initally, we first rot the oranges around the first orange, then around the second and then around the third
    // and only then will we go to the second level. 
    //This way, we need not add a visited orange back to the queue whatsoever. 
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> dir(4);
    dir[0] = {1, 0};
    dir[1] = {-1, 0};
    dir[2] = {0, -1};
    dir[3] = {0, 1};
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    queue<pair<int, int>> q;

    //Push all the cells with 2 into the queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    //Stores the time taken by each cell to rot
    vector<vector<int>> dis(n, vector<int>(m, 0));
    int ans = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        ans = max(ans, dis[x][y]);
        int newx, newy;
        for (int i = 0; i < 4; i++)
        {
            newx = x + dir[i].first;
            newy = y + dir[i].second;
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] && grid[newx][newy] == 1)
            {
                dis[newx][newy] = dis[x][y] + 1;
                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                return -1;
            }
        }
    }
    return ans;
}

int orangesRotting(vector<vector<int>> &grid)
{
    vector<vector<int>> time(grid);
    set<pair<int, int>> s;
    for (int i = 0; i < time.size(); i++)
    {
        for (int j = 0; j < time[i].size(); j++)
        {
            if (grid[i][j] == 2)
                s.insert({i, j});
            if (time[i][j] == 0)
                time[i][j] = -1;
            if (time[i][j] == 1)
                time[i][j] = INT_MAX;
            if (time[i][j] == 2)
                time[i][j] = 0;
        }
    }
    int n = grid.size();
    queue<vector<int>> q;
    for (pair<int, int> p : s)
    {
        q.push({p.first, p.second});
        while (!q.empty())
        {
            int i = q.front()[0];
            int j = q.front()[1];
            int m = grid[i].size();
            q.pop();
            if (grid[i][j] == 0)
                continue;
            if (grid[i][j] == 2)
            {
                if (j - 1 >= 0 && grid[i][j - 1] != 0)
                {
                    if (grid[i][j - 1] == 1 || (grid[i][j] == 2 && time[i][j - 1] > time[i][j] + 1))
                        q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                    time[i][j - 1] = min(time[i][j - 1], time[i][j] + 1);
                }
                if (j + 1 < m && grid[i][j + 1] != 0)
                {
                    if (grid[i][j + 1] == 1 || (grid[i][j] == 2 && time[i][j + 1] > time[i][j] + 1))
                        q.push({i, j + 1});
                    grid[i][j + 1] = 2;
                    time[i][j + 1] = min(time[i][j + 1], time[i][j] + 1);
                }
                if (i + 1 < n && grid[i + 1][j] != 0)
                {
                    if (grid[i + 1][j] == 1 || (grid[i][j] == 2 && time[i + 1][j] > time[i][j] + 1))
                        q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                    time[i + 1][j] = min(time[i + 1][j], time[i][j] + 1);
                }
                if (i - 1 >= 0 && grid[i - 1][j] != 0)
                {
                    if (grid[i - 1][j] == 1 || (grid[i][j] == 2 && time[i - 1][j] > time[i][j] + 1))
                        q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                    time[i - 1][j] = min(time[i - 1][j], time[i][j] + 1);
                }
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (time[i][j] > 0)
                maxCount = max(maxCount, time[i][j]);
        }
    }
    return maxCount == INT_MAX ? -1 : maxCount;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    //{{0,1,1,2},{0,1,1,0},{1,1,2,0}};
    //    {
    //     {2,0,1,1,1,1,1,1,1,1},
    //     {1,0,1,0,0,0,0,0,0,1},
    //     {1,0,1,0,1,1,1,1,0,1},
    //     {1,0,1,0,1,0,0,1,0,1},
    //     {1,0,1,0,1,0,0,1,0,1},
    //     {1,0,1,0,1,1,0,1,0,1},
    //     {1,0,1,0,0,0,0,1,0,1},
    //     {1,0,1,1,1,1,1,1,0,1},
    //     {1,0,0,0,0,0,0,0,0,1},
    //     {1,1,1,1,1,1,1,1,1,1}
    //    };
    //
    cout << orangesRottingIdeal(grid) << endl;
    return 0;
}