#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(19);
    pq.push(38);
    pq.push(30);
    // pq.pop();

    // cout << pq.top();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    p.push({10, 5});
    p.push({5, 10});
    cout << p.top().first << " " << p.top().second;
    return 0;
}