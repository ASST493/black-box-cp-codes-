#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll timer_;
vector <vector<pair<ll,ll>>> g;   // {neighbor, edge id}
vector <ll> tin, low;
vector <ll> vis, isBridge;

void dfs(ll u, ll parEdge)
{
    vis[u] = 1;
    tin[u] = low[u] = ++timer_;
    for (auto [to, id] : g[u])
    {
        if (id == parEdge)
        {
            continue;
        }
        if (vis[to])
        {
            low[u] = min(low[u], tin[to]);
        } else
        {
            dfs(to, id);
            low[u] = min(low[u], low[to]);
            if (low[to] > tin[u])
            {
                isBridge[id] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, q; cin >> n >> m >> q;
        g.assign(n + 1, {});
        vector<array<ll,3>> e(m + 1);
        for (ll i = 1; i <= m; i++)
        {
            ll a, b; ll w; cin >> a >> b >> w;
            e[i] = {a, b, w};
            g[a].push_back({b, i});
            g[b].push_back({a, i});
        }
        tin.assign(n + 1, 0); low.assign(n + 1, 0);
        vis.assign(n + 1, 0); isBridge.assign(m + 1, 0);
        timer_ = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1);
            }
        }
    }
}
