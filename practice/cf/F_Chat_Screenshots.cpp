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

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> adj(n);
    vector<ll> inDeg(n, 0);
    for (ll i = 0; i < k; i++)
    {
        vll scr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> scr[i];
            scr[i]--;
        }
        for (ll i = 1; i < n - 1; i++)
        {
            adj[scr[i]].push_back(scr[i + 1]);
            inDeg[scr[i + 1]]++;
        }
    }

    vll topo;
    queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto e = q.front();
        q.pop();
        topo.push_back(e);

        for (auto f : adj[e])
        {
            if (--inDeg[f] == 0)
            {
                q.push(f);
            }
        }
    }

    if (topo.size() == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
}