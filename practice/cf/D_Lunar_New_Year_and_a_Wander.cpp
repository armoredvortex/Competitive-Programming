#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(0);
    vll visited(n, 0);
    visited[0] = 1;
    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        cout << e + 1 << ' ';
        for (auto f : adj[e])
        {
            if (!visited[f])
            {
                visited[f] = true;
                pq.push(f);
            }
        }
    }
}