#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        long long a = -1, b = -1;
        int idxA, idxB;
        // for (int i = 0, j = n - 1; i < j; i++, j--)
        // {
        //     a = max(a, h[i]);
        //     b = max(b, h[i]);
        // }
        for (int i = 0; i < n; i++)
        {
            if (a < h[i])
            {
                a = h[i];
                idxA = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (b < h[i] && i != idxA)
            {
                b = h[i];
                idxB = i;
            }
        }

        cout << min(idxA, idxB) << " " << max(idxA, idxB) << endl;
    }

    return 0;
}