#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    // sobar value k intMax kora and i=j hole 1 kora
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }

    // sobghulo edge input neoa
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a]=c; //undricted
    }
    // edge print kore dekhar jonno sudhu no need
    //  for (int k = 0; k < n; k++)
    //  {
    //      for (int i = 0; i < n; i++)
    //          for (int j = 0; j < n; j++)
    //              cout << i << " " << k << " " << j << endl;
    //  }

    // main logic
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
    }

    // matrix print kora
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (adj_mat[i][j] == INT_MAX)
                cout << "INF" << " ";
            else
                cout << adj_mat[i][j] << "   ";
        cout << endl;
    }

    return 0;
}

// 4 5
// 0 1 3
// 0 2 6
// 1 2 2 
// 1 3 5
// 2 3 4