#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pll pair<long long,long long>
#define vll vector<long long>
#define vld vector<long double>
#define vpll vector<pair<long long,long long>>
#define all(x) (x).begin(),(x).end()
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define f(a) for(auto &x:a){cin >> x;}

const int INF = 1000000000;

ll n , m;
vll d , p;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.assign(n,{});
    d.assign(n,0);
    p.assign(n,-1);
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b , c;
        cin >> a >> b >> c;
        a-- , b--;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    dijkstra(0);
}