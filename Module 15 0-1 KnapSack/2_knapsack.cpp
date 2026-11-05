#include <bits/stdc++.h>
using namespace std;
int val[100], weight[100];
int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight < 0)
        return 0;

    if (weight[i] < mx_weight)
    {
        // 2 option
        // 1.bag e rakhbo //2.bag e rakhbo na
        int op1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        return max(op1, op2);
    }
    else
    {
        // 1 option
        // bag e rakhte parbo na
        return knapsack(i - 1, mx_weight);
    }
}
int main()
{
    int n, mx_waight;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> mx_waight;
    int ans = knapsack(n - 1, mx_waight);
    cout << ans;

    return 0;
}