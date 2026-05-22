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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    const int NN = 1e5 + 10;
    vll dp(NN, 0);
    dp[0] = 1;
    for (ll j = 0; j < n; j++)
    {
        vll dpc = dp;
        for (ll i = v[j]; i < NN; i++)
        {
            if (dp[i - v[j]])
            {
                dpc[i] = 1;
            }
        }
        dp = dpc;
    }
    // cerr << dp;
    cout << count(dp.begin(), dp.end(), 1) - 1 << '\n';
    for (int i = 1; i < NN; i++)
    {
        if (dp[i])
        {
            cout << i << ' ';
        }
    }
}