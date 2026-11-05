#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    // for (int i = 0; i < e; i++)
    // {
    //     for (int j = 0; j < e; j++)
    //     {
    //         adj_mat[i][j] = 0;
    //     }
    // }
    memset(adj_mat, 0, sizeof(adj_mat)); // shortcut

    //diagonal gulo 1 kore debo
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                adj_mat[i][j] = 1;
//matrix e input neoa
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            adj_mat[a][b] = 1;
            adj_mat[b][a] = 1; //for undricted graph
            // if (i == j)
            //     adj_mat[i][j] = 1;
        }
    }

    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}