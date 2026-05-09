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
    for (ll i = 1; i < n + 1; i++)
    {
        mp[i].push_back(-1);
    }
    for (ll i = 0; i < n; i++)
    {
        mp[v[i]].push_back(i);
    }

    for (ll i = 1; i < n + 1; i++)
    {
        mp[i].push_back(n);
    }

    // cerr << mp << '\n';
    map<ll, ll> kamazing;
    for (ll i = 1; i <= n; i++)
    {
        ll mx = 0;
        for (ll j = 0; j < mp[i].size() - 1; j++)
        {
            mx = max(mx, mp[i][j + 1] - mp[i][j]);
        }

        if (kamazing.find(mx) == kamazing.end())
        {
            kamazing[mx] = i;
        }
        else
        {
            if (kamazing[mx] > i)
            {
                kamazing[mx] = i;
            }
        }
    }

    ll mn = -1;
    for (ll i = 1; i < n + 1; i++)
    {
        if (kamazing.find(i) == kamazing.end() && mn == -1)
        {
            cout << -1 << ' ';
        }
        else if (kamazing.find(i) == kamazing.end() && mn != -1)
        {
            cout << mn << ' ';
        }
        else
        {
            if (mn != -1)
            {
                mn = min(mn, kamazing[i]);
            }
            else
            {
                mn = kamazing[i];
            }
            cout << mn << ' ';
        }
    }
    cout << '\n';
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