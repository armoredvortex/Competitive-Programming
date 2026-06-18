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

const ll mod = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;
    ll d;
    cin >> d;

    vector<vector<vector<ll>>> dp(s.size(), vector<vector<ll>>(d, vector<ll>(2, 0)));
    for (ll i = 0; i < 10; i++)
    {
        if (i < s[0] - '0')
        {
            dp[0][i % d][0] += 1;
        }
        if (i == s[0] - '0')
        {
            dp[0][i % d][1] += 1;
        }
    }
    for (ll i = 1; i < s.size(); i++)
    {
        for (ll j = 0; j < d; j++)
        {
            for (ll k = 0; k < 10; k++)
            {
                dp[i][(j + k) % d][0] = (dp[i][(j + k) % d][0] + dp[i - 1][j][0]) % mod;
                if (k < s[i] - '0')
                {
                    dp[i][(j + k) % d][0] = (dp[i][(j + k) % d][0] + dp[i - 1][j][1]) % mod;
                }
                if (k == s[i] - '0')
                {
                    dp[i][(j + k) % d][1] = (dp[i][(j + k) % d][1] + dp[i - 1][j][1]) % mod;
                }
            }
        }
    }

    ll ans = 0;
    ans = (mod + dp.back()[0][0] + dp.back()[0][1] - 1) % mod;
    cout << ans << '\n';

    // cerr << dp;
}