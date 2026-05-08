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
    ll n, a, b;
    cin >> n >> a >> b;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll dist(n);
    dist[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        dist[i] = v[i] - v[i - 1];
    }

    // cerr << dist;

    ll ct = n;
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if ((ct - 1) * b > a)
        {
            ans += (a * dist[i] + b * dist[i]);
        }
        else
        {
            ans += ct * b * dist[i];
        }
        ct--;
    }
    ans += b * dist.back();
    cout << ans << '\n';
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