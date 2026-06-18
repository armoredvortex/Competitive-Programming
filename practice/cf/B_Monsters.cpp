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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = (v[i] - 1) % k;
    }
    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[v[i]].push_back(i);
    }
    vll order;
    for (auto e : mp)
    {
        for (ll j = e.second.size() - 1; j >= 0; j--)
        {
            order.push_back(e.second[j]);
        }
    }
    reverse(order.begin(), order.end());
    for (auto e : order)
    {
        cout << e + 1 << ' ';
    }
    cout << '\n';
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