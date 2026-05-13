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

    vll factors;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (n / i != i)
            {
                factors.push_back(n / i);
            }
        }
    }

    ll ans = 0;
    for (auto e : factors)
    {
        if (e == n)
        {
            ans++;
            continue;
        }

        vll ggs;
        for (ll i = 0; i < e; i++)
        {
            ll g = abs(v[i + e] - v[i]);
            ll j = i;
            while (j + e < n)
            {
                g = gcd(g, abs(v[j + e] - v[j]));
                j += e;
            }
            if (g)
            {
                ggs.push_back(g);
            }
        }
        if (ggs.size() == 0)
        {
            ans++;
            continue;
        }
        ll k = ggs[0];
        for (auto e : ggs)
        {
            k = gcd(k, e);
        }
        if (k >= 2)
        {
            ans++;
        }
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