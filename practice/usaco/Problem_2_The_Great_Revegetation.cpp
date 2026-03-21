#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

// #ifndef ONLINE_JUDGE
// #include "debugging.h"
// #endif

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

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

    for (auto &e : adj)
    {
        sort(e.begin(), e.end());
    }

    vector<ll> color(n, -1);
    for (ll i = 0; i < n; i++)
    {

        vector<ll> filled(4, 0);
        for (auto f : adj[i])
        {
            if (color[f] != -1)
            {
                filled[color[f]] = 1;
            }
        }
        for (ll j = 0; j < 4; j++)
        {
            if (filled[j] == 0)
            {
                color[i] = j;
                break;
            }
        }
    }
    for (auto e : color)
    {
        cout << e + 1;
    }
}