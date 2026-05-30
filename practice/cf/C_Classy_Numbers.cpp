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

ll ans(ll x)
{
    if (x == 0)
    {
        return 1;
    }
    vll digits;
    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());

    ll dp[digits.size()][10][4][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0][0][0] = 1;
    for (int i = 1; i < digits[0]; i++)
    {
        dp[0][i][1][0] = 1;
    }
    dp[0][digits[0]][1][1] = 1;

    for (ll i = 1; i < digits.size(); i++)
    {
        for (ll j = 0; j < 10; j++)
        {
            for (ll ct = 0; ct < 4; ct++)
            {
                if (ct != 0)
                {
                    for (ll k = 1; k < 10; k++)
                    {
                        dp[i][k][ct][0] += dp[i - 1][j][ct - 1][0];
                    }
                    for (ll k = 1; k < digits[i]; k++)
                    {
                        dp[i][k][ct][0] += dp[i - 1][j][ct - 1][1];
                    }
                    if (digits[i] != 0)
                    {

                        dp[i][digits[i]][ct][1] += dp[i - 1][j][ct - 1][1];
                    }
                }
                dp[i][0][ct][0] += dp[i - 1][j][ct][0];
                if (digits[i] == 0)
                {
                    dp[i][0][ct][1] += dp[i - 1][j][ct][1];
                }
                else
                {
                    dp[i][0][ct][0] += dp[i - 1][j][ct][1];
                }
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < 10; i++)
    {
        for (ll ct = 0; ct < 4; ct++)
        {
            ans += dp[digits.size() - 1][i][ct][0];
            ans += dp[digits.size() - 1][i][ct][1];
        }
    }

    return ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << ans(b) - ans(a - 1) << '\n';
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