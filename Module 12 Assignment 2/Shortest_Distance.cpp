#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    long long int adj_matx[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                adj_matx[i][j] = 0;
            else
                adj_matx[i][j] = LLONG_MAX;

    while (e--)
    {
        long long a, b, w;
        cin >> a >> b >> w;
        adj_matx[a][b] = min(adj_matx[a][b], w);
    }

    // floyd_warshell
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_matx[i][k] != LLONG_MAX && adj_matx[k][j] != LLONG_MAX && adj_matx[i][k] + adj_matx[k][j] < adj_matx[i][j])
                {
                    adj_matx[i][j] = adj_matx[i][k] + adj_matx[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (adj_matx[x][y] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matx[x][y] << endl;
    }

    return 0;
}