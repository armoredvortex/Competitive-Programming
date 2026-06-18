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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        v[i] = {min(a, b), max(a, b)};
    }

    ll total = n * (n + 1) / 2;
    sort(v.begin(), v.end(), comp);
    ll idx = 0;
    ll mx = -1;
    ll ct = 0;
    for (ll i = 0; i < n; i++)
    {
        while (idx < m && v[idx].second <= i)
        {
            mx = max(mx, v[idx].first);
            idx++;
        }
        ct += max(0ll, mx + 1);
        // cerr << ct << '\n';
    }

    cout << total - ct << '\n';
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