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

    vector<pair<ll, ll>> v;
    ll curr = 1, sz = 1;
    while (curr <= n)
    {
        v.push_back({curr, curr + sz - 1});
        curr += sz;
        sz++;
    }

    reverse(v.begin(), v.end());
    // for (auto e : v)
    // {
    //     cerr << e << '\n';
    // }
    ll ans = 0;

    curr = n;
    int i;
    int sz2 = 0;
    sz = v.size();
    for (i = 0; i < v.size(); i++)
    {
        // cerr << curr << '\n';
        // if (curr < v[i].first)
        // {
        //     break;
        // }
        // else
        // {
        // cerr << curr << ' ' << v[i].first << '-' << v[i].second << ' ' << curr + sz2 << '\n';
        for (ll j = max(curr, v[i].first); j <= min(v[i].second, curr + sz2); j++)
        {
            ans += j * j;
        }
        sz2++;
        curr -= (v.size() - i);
        // }
    }

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