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

bool isPalindrome(ll i)
{
    vector<ll> digs;
    while (i)
    {
        digs.push_back(i % 10);
        i /= 10;
    }

    for (ll i = 0; i < digs.size(); i++)
    {
        if (digs[i] != digs[digs.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<ll> pnums;
    for (ll i = 1; i < 4 * (1e4) + 10; i++)
    {
        if (isPalindrome(i))
        {
            pnums.push_back(i);
        }
    }

    vll dp(4 * (1e4) + 10);
    dp[0] = 1;
    for (auto e : pnums)
    {
        for (ll i = 1; i < 4 * (1e4) + 10; i++)
        {
            if (i - e >= 0)
            {
                dp[i] = (dp[i] + dp[i - e]) % (1000000007);
            }
        }
    }

    // cerr << dp;
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}