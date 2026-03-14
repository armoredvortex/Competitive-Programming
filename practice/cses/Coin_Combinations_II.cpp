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

const ll MOD = 1000000007;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, x;
    cin >> n >> x;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll dp[x + 1];
    for (ll i = 0; i < x + 1; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = v[i]; j < x + 1; j++)
        {
            dp[j] = (dp[j - v[i]] + dp[j]);
            if (dp[j] >= MOD)
            {
                dp[j] -= MOD;
            }
        }
    }

    cout << dp[x];
}