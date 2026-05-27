#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

vector<ll> digs(ll x)
{
    vector<ll> ret;
    while (x)
    {
        ret.push_back(x % 10);
        x /= 10;
    }
    return ret;
}

ll solve(ll x)
{
    if (x == 0)
    {
        return 1;
    }
    vector<ll> digits = digs(x);
    reverse(digits.begin(), digits.end());

    vector<vector<vector<ll>>> dp(digits.size(), vector<vector<ll>>(10, vector<ll>(2)));
    for (ll i = 0; i < digits[0]; i++)
    {
        dp[0][i][0] = 1;
    }
    dp[0][digits[0]][1] = 1;

    for (ll i = 1; i < digits.size(); i++)
    {
        for (ll j = 0; j < 10; j++)
        {

            for (ll k = 0; k < 10; k++)
            {
                if (j != k)
                    dp[i][k][0] += dp[i - 1][j][0];
            }
            for (ll k = 0; k < digits[i]; k++)
            {
                if (j != k)
                    dp[i][k][0] += dp[i - 1][j][1];
            }
        }
        if (digits[i] != digits[i - 1])
            dp[i][digits[i]][1] += dp[i - 1][digits[i - 1]][1];
    }

    ll ans = 0;
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 10; j++)
        {
            ans += dp.back()[j][i];
        }
    }

    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll a, b;
    cin >> a >> b;

    if (a == 0)
    {
        cout << solve(b);
    }
    else
    {
        cout << solve(b) - solve(a - 1);
    }
}