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

    int max_val = 1;
    while (max_val <= n)
    {
        max_val *= 2;
    }

    ll ans = 0;

    vector<int> freq(max_val, 0);
    freq[0] = 1;

    ll run = 0;
    for (ll i = 0; i < n; i++)
    {
        run ^= v[i];

        for (ll j = 0; j * j < max_val; j++)
        {
            ll req = run ^ (j * j);
            ans += freq[req];
        }
        freq[run]++;
    }

    cout << n * (n + 1) / 2 - ans << '\n';
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