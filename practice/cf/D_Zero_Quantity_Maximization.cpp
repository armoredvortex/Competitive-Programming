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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vll a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    map<pair<ll, pair<ll, ll>>, ll> mp;

    ll extra = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != 0 && b[i] != 0)
        {
            ll g = gcd(b[i], a[i]);
            pair<ll, ll> p = {abs(b[i] / g),
                              abs(a[i] / g)};

            ll sgn = -1;
            if (a[i] < 0 && b[i] < 0 || a[i] > 0 && b[i] > 0)
            {
                sgn = +1;
            }

            mp[{sgn, p}]++;
        }
        else if (a[i] == 0 && b[i] == 0)
        {
            extra++;
        }
        else if (b[i] == 0)
        {
            mp[{1, {0, 0}}]++;
        }
    }

    // cerr << mp;
    ll mx = 0;
    for (auto e : mp)
    {
        mx = max(mx, e.second);
    }
    cout << mx + extra;

    return 0;
}