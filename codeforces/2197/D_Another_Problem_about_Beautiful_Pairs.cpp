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

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<ll, vll> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[v[i]].push_back(i);
    }

    // cerr << mp;

    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                ll f1 = j;
                ll f2 = i / j;

                // cerr << f1 << ' ' << f2 << '\n';
                for (ll p1 = 0; p1 < mp[f1].size(); p1++)
                {
                    for (ll p2 = 0; p2 < mp[f2].size(); p2++)
                    {
                        if (mp[f2][p2] - mp[f1][p1] == i)
                        {

                            ans++;
                            cerr << mp[f2][p2] + 1 << ' ' << mp[f1][p1] + 1 << '\n';
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return;
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