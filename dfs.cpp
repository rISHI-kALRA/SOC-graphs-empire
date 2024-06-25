#include <bits/stdc++.h>
using namespace std;

int n , m; // n = number of nodes , m = number of edgs
vector<vector<int> > adj;
vector<int> color; // will help in distinguishing a graph as bipartite as the nodes are alternately colored 1 and 2 as we go down a path. All the nodes are initialized to 0.

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

int main()
{
    cin >> n >> m;
    dfs_timer = 0;
    color.assign(n,0);
    adj.assign(n,{});
    for(int i = 0 ; i < m ; i++)
    {
        int a , b;
        cin >> a >> b;
        a-- , b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
}