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
    ll n;
    cin >> n;

    vector<pair<ll, ll>> edges(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n - 1; i++)
    {
        mp[edges[i].first].push_back(i);
        mp[edges[i].second].push_back(i);
    }

    vll visited(n, 0);
    queue<ll> q;
    while (!q.empty())
    {
        ll sz = q.size();
        for (ll i = 0; i < sz; i++)
        {
            auto e = q.front();
            q.pop();

            
        }
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