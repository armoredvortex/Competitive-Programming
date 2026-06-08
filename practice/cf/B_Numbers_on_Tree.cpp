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

void subtr(vector<vector<ll>> &adj, ll node, ll parent, vector<ll> &szs)
{
    ll sz = 1;
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            subtr(adj, e, node, szs);
            sz += szs[e];
        }
    }
    szs[node] = sz;
}

void solve(vector<vector<int>> &adj, int node, int parent, vector<int> &ans)
{
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    ll root;
    vector<vector<ll>> adj(n);
    vector<ll> c(n), szs(n);
    for (ll i = 0; i < n; i++)
    {
        ll pi, ci;
        cin >> pi >> ci;
        c[i] = ci;
        if (pi == 0)
        {
            root = i;
        }
        else
        {
            adj[i].push_back(pi - 1);
            adj[pi - 1].push_back(i);
        }
    }

    subtr(adj, root, -1, szs);
    cerr << adj << '\n';
    cerr << c << '\n'
         << szs;
    vll ans(n);
    solve(adj, root, -1, ans);
}