#include <bits/stdc++.h>
using namespace std;
vector<int> adj_lst[1000];
bool vis[1000];
void bfs(int src)
{
   queue<int> q;
   q.push(src);
   vis[src] = true;
   while (!q.empty())
   { // ber kore ana
      int par = q.front();
      q.pop();
      // node niye kaj
      cout << par << " ";
      // queue te push kora
      for (int child : adj_lst[par])
      {
         if (vis[child] == false)
         {
            q.push(child);
            vis[child] = true;
            // cout<<child<<" ";
         }
      }
   }
}
int main()
{
   int n, e;
   cin >> n >> e;
   while (e--)
   {
      int a, b;
      cin >> a >> b;
      adj_lst[a].push_back(b);
      adj_lst[b].push_back(a);
   }
   memset(vis, false, sizeof(vis));
   bfs(0);
   // for (int i = 0; i < n; i++)
   // {
   //    cout << i << "-> ";
   //    for (int c : adj_lst[i])
   //    {
   //       cout << c << " ";
   //    }
   //    cout << endl;
   // }

   return 0;
}