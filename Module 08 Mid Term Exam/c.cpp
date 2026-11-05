#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent_cell[1005][1005];

int n, m;

// Right, Left, Up, Down
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main()
{
    cin >> n >> m;

    int sx, sy, dx_exit, dy_exit;

    // Input + find R and D
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'D')
            {
                dx_exit = i;
                dy_exit = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    // BFS
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    bool found = false;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        int x = par.first;
        int y = par.second;

        // Exit reached
        if (x == dx_exit && y == dy_exit)
        {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (!valid(nx, ny))
                continue;

            if (vis[nx][ny])
                continue;

            if (grid[nx][ny] != '.' && grid[nx][ny] != 'D')
                continue;

            vis[nx][ny] = true;
            parent_cell[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }

    // Path mark (if found)
    if (found)
    {
        int x = dx_exit;
        int y = dy_exit;

        while (grid[x][y] != 'R')
        {
            auto p = parent_cell[x][y];

            if (grid[p.first][p.second] == '.')
                grid[p.first][p.second] = 'X';

            x = p.first;
            y = p.second;
        }
    }

    // Output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }

    return 0;
}