#include <bits/stdc++.h>
using namespace std;
long long fibo(long long n) //O(2^N)
{
    if (n < 2)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    long long n;
    cin >> n;
    cout << fibo(n);

    return 0;
}