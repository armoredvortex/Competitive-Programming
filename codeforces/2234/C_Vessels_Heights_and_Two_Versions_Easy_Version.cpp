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

    for (ll i = 0; i < n; i++)
    {
        vll water(n), waterl(n), waterr(n);
        waterl[i] = 0;
        waterr[i] = 0;
        ll k = (i + 1) % n;
        for (ll j = 0; j < n - 1; j++)
        {
            waterl[k] = max(v[(k + n - 1) % n], waterl[(k + n - 1) % n]);
            k = (k + 1) % n;
        }
        k = (i + n - 1) % n;
        for (ll j = 0; j < n - 1; j++)
        {
            waterr[k] = max(v[k], waterr[(k + 1) % n]);
            k = (k + n - 1) % n;
        }
        for (ll j = 0; j < n; j++)
        {
            water[j] = min(waterl[j], waterr[j]);
        }

        cout << accumulate(water.begin(), water.end(), 0ll) << ' ';
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