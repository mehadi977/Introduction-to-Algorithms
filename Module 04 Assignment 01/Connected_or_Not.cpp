#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(10000);
vector<bool> vis(10000, false);
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_lst[a].push_back(b);
    }
    int q;
    cin >> q;
    while (q--)
    {
        bool found = false;
        int a, b;
        cin >> a >> b;
        if (a == b)
            found = true;
        for (int x : adj_lst[a])
        {
            if (b == x)
            {
                found = true;
                break;
            }
        }
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}