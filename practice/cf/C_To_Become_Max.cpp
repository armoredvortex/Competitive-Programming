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
    ll n, k;
    cin >> n >> k;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = *max_element(all(v));
    ll spent = 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (v[i + 1] >= v[i])
        {
            if (spent < k)
            {
                ll d = min(k - spent, v[i + 1] + 1 - v[i]);
                spent += d;
                v[i] += d;
                ans = max(ans, v[i]);
            }
        }
        else
        {
            spent = 0;
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