#include <bits/stdc++.h>
using namespace std;
int val[100], weight[100];
int dp[100][100];
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
    int n, mx_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cin >> mx_weight;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;
    int ans = kapsack(n - 1, mx_weight);
    cout << ans;
    return 0;
}