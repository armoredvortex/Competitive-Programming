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
    vector<vector<ll>> v(m, vector<ll>(3));
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    vector<ll> dist(n + 1, INT_MIN);
    dist[1] = 0;

    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (dist[v[j][0]] != INT_MIN)
            {
                dist[v[j][1]] = max(dist[v[j][1]], dist[v[j][0]] + v[j][2]);
            }
        }
    }
    vector<ll> d2 = dist;
    for (ll j = 0; j < m; j++)
    {
        if (dist[v[j][0]] != INT_MIN)
        {
            dist[v[j][1]] = max(dist[v[j][1]], dist[v[j][0]] + v[j][2]);
        }
    }
    set<ll> changed;
    for (ll i = 0; i < n + 1; i++)
    {
        if (d2[i] != dist[i])
        {
            changed.insert(i);
        }
    }

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        adj[v[i][1]].push_back(v[i][0]);
    }

    stack<ll> st;
    st.push(n);
    vll visited(n + 1, 0);
    visited[n] = 1;
    while (!st.empty())
    {
        auto e = st.top();
        st.pop();
        if (changed.find(e) != changed.end())
        {
            cout << -1 << '\n';
            return 0;
        }
        for (auto f : adj[e])
        {
            if (!visited[f])
            {
                st.push(f);
                visited[f] = 1;
            }
        }
    }
    if (d2.back() == INT_MIN)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << d2.back() << '\n';
    }
}