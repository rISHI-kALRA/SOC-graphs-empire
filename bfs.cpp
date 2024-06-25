#include <bits/stdc++.h>
using namespace std;

int n , m; // n = number of nodes , m = number of edgs
vector<vector<int> > adj;
vector<int> d, p; // store distance from node 's' and parent of each node respectively

void bfs()
{
    queue<int> q;
    d.assign(n , 0);
    p.assign(n , -1);
    vector<bool> used(n);
    int s;
    cin >> s; // input the starting node
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.assign(n , {});
    for(int i = 0 ; i < m ; i++)
    {
        int a , b;
        cin >> a >> b;
        a-- , b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
}