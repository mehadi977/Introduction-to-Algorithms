#include <bits/stdc++.h>
using namespace std;
bool found = false;
bool vis[100005];
void fnd(int n, int i)
{
    if (found)
        return;
    if (n == i)
    {
        found = true;
        return;
    }
    if (i > n || vis[i])
        return;
    vis[i] = true;
    fnd(n, i + 3);
    fnd(n, i * 2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        found = false;
        memset(vis, false, sizeof(vis));
        fnd(n, 1);
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}