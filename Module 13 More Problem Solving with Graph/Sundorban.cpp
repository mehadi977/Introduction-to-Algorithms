// Problem Link: https://school.outsbook.com/problems/problemdetails/10106

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
char grid[40][40];
bool vis[40][40];
int level[40][40];
vector<pair<int, int> > d;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{

    d.push_back({-1, 0});
    d.push_back({1, 0});
    d.push_back({0, -1});
    d.push_back({0, 1});
    int si, sj, di, dj;

    while (cin >> n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'S')
                    si = i, sj = j;
                if (grid[i][j] == 'E')
                    di = i, dj = j;
            }
        }
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);
        cout << level[di][dj]<<endl;
    }

    return 0;
}

// test case:
// 1:
//  5
//  S P P P P
//  T P T P P
//  T P P P P
//  P T E T T
//  P T P T T
// ou:
//  5
// 2:

// ou:
