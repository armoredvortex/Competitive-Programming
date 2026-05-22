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

const ll MOD = 1e9 + 7;

const ll mod = 1000000007;
ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1)
            ans = ans * b % mod;
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    ll inv2 = modpow(2, mod - 2);

    if (n < 3)
    {
        cout << 0;
        return 0;
    }
    ll sum1 = n * (n + 1) / 2;
    if (sum1 % 2)
    {
        cout << 0 << '\n';
        return 0;
    }
    ll sum = sum1 / 2;
    vll dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vll dpc = dp;
        for (ll j = i; j < sum + 1; j++)
        {
            dpc[j] = (dp[j] + dp[j - i]) % MOD;
        }

        dp = dpc;
    }
    cout << (dp[sum] * inv2) % MOD;
}