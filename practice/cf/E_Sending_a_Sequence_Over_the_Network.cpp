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
    ll n;
    cin >> n;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // dp[i] = sequence 1..i is valid??

    for (int i = 1; i <= n; i++)
    {
        int idx = i - 1;
        if (i - v[idx] - 1 >= 0 && dp[i - v[idx] - 1])
        {
            dp[i] = 1;
        }
        if (dp[i - 1] && i + v[idx] <= n)
        {
            dp[i + v[idx]] = 1;
        }
    }

    cout << (dp[n] ? "YES\n" : "NO\n");
    // cerr << dp << '\n';
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