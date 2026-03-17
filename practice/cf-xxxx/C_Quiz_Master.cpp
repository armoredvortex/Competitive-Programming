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

void add_val(map<ll, ll> &mp, ll val, ll m)
{
    for (ll i = 1; i <= sqrt(val); i++)
    {
        if (val % i == 0)
        {
            if (i <= m)
            {
                mp[i]++;
            }
            if (i != val / i)
            {
                if (val / i <= m)
                {
                    mp[val / i]++;
                }
            }
        }
    }
}

void remove_val(map<ll, ll> &mp, ll val, ll m)
{
    for (ll i = 1; i <= sqrt(val); i++)
    {
        if (val % i == 0)
        {
            if (i <= m)
            {
                if (--mp[i] == 0)
                {
                    mp.erase(i);
                }
            }

            if (val / i <= m)
            {
                if (i != val / i)
                {
                    if (--mp[val / i] == 0)
                    {
                        mp.erase(val / i);
                    }
                }
            }
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll left = 0, right = 0;
    ll ans = LONG_LONG_MAX;
    map<ll, ll> mp;
    while (right < n)
    {
        add_val(mp, v[right], m);
        // cerr << mp << "\n\n";
        while (mp.size() == m)
        {
            ans = min(ans, v[right] - v[left]);
            remove_val(mp, v[left], m);

            left++;
        }
        right++;
    }
    if (ans == LONG_LONG_MAX)
    {
        cout << -1 << '\n';
        return;
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