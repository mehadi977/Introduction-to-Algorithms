#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];
int kapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight < 0)
        return 0;
    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];
    if (weight[i] <= mx_weight)
    {
        int op1 = kapsack(i - 1, mx_weight - weight[i]) + val[i];
        int op2 = kapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = kapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= w; j++)
                dp[i][j] = -1;
        int ans = kapsack(n - 1, w);
        cout << ans << endl;
    }

    return 0;
}