#include <bits/stdc++.h>
using namespace std;
char grind[1005][1005];
bool vis[1005][1005];
int n, m;
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}
void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;
        if (valid(ci, cj) && vis[ci][cj] == false && grind[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grind[i][j];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << grind[i][j];
    //     cout << endl;
    // }
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grind[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grind[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    // cout << si << " " << sj << endl
    //      << di << " " << dj<<endl;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);
    if (vis[di][dj] == true)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}