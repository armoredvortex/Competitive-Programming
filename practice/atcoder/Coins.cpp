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
    vector<long double> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // cerr << v << '\n';

    vector<vector<long double>> dp(n, vector<long double>(n + 1, 0));
    dp[0][0] = 1 - v[0];
    dp[0][1] = v[0];

    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < n + 1; j++)
        {
            dp[i][j] += dp[i - 1][j] * (1 - v[i]);
            if (j >= 1)
            {
                dp[i][j] += dp[i - 1][j - 1] * v[i];
            }
        }
    }
    long double ans = 0;
    for (ll i = (n + 1) / 2; i <= n; i++)
    {
        ans += dp.back()[i];
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
}