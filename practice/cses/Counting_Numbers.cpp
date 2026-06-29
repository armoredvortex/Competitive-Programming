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

ll count(ll a)
{
    if (a < 0)
    {
        return 0;
    }
    else if (a == 0)
    {
        return 1;
    }

    vector<int> digits;
    while (a)
    {
        digits.push_back(a % 10);
        a /= 10;
    }
    reverse(digits.begin(), digits.end());

    vector<vector<vector<ll>>> dp(digits.size(), vector<vector<ll>>(10, vector<ll>(2, 0)));
    for (ll i = 1; i < digits[0]; i++)
    {
        dp[0][i][0] = 1;
    }
    dp[0][digits[0]][1] = 1;

    for (ll i = 1; i < digits.size(); i++)
    {
        for (ll j = 1; j < 10; j++)
            dp[i][j][0]++;
        for (ll j = 0; j < 10; j++)
        {
            for (ll k = 0; k < 10; k++)
            {
                if (j != k)
                {
                    dp[i][k][0] += dp[i - 1][j][0];
                }
            }
        }
        for (ll j = 0; j < digits[i]; j++)
        {
            if (j != digits[i - 1])
            {
                dp[i][j][0] += dp[i - 1][digits[i - 1]][1];
            }
        }
        if (digits[i] != digits[i - 1])
        {
            dp[i][digits[i]][1] += dp[i - 1][digits[i - 1]][1];
        }
    }

    ll ans = 0;
    for (ll i = 0; i < 10; i++)
    {
        ans += dp.back()[i][0];
        ans += dp.back()[i][1];
    }
    return ans + 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a - 1) << '\n';
}