#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, m, q;
    cin >> n >> m >> q;
    long long int adj_matx[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_matx[i][j] = 0;
            else
                adj_matx[i][j] = LONG_LONG_MAX;
        }
    while (m--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_matx[a][b] = min(adj_matx[a][b], c);
        adj_matx[b][a] = min(adj_matx[a][b], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (adj_matx[i][k] != LONG_LONG_MAX && adj_matx[k][j] != LONG_LONG_MAX && adj_matx[i][k] + adj_matx[k][j] < adj_matx[i][j])
                    adj_matx[i][j] = adj_matx[i][k] + adj_matx[k][j];
            }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         if (adj_matx[i][j] == INT_MAX)
    //             cout << "INF" << " ";
    //         else
    //             cout << adj_matx[i][j] << "   ";
    //     cout << endl;
    // }
    while (q--)
    {
        long long int s, d;
        cin >> s >> d;
        if (adj_matx[s][d] == LONG_LONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matx[s][d] << endl;
    }

    return 0;
}