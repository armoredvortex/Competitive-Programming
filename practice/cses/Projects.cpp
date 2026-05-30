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
    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i][1] >> v[i][0] >> v[i][2];
    }

    sort(v.begin(), v.end());

    vll dp(n);
    dp[0] = v[0][2];
    for (ll i = 1; i < n; i++)
    {
        auto e = v[i];
        vector<ll> t = {e[1], -1, -1};
        auto it = upper_bound(v.begin(), v.end(), t) - v.begin() - 1;
        if (it == -1)
        {
            dp[i] = max(dp[i - 1], e[2]);
        }
        else
        {
            dp[i] = max(dp[i - 1], v[i][2] + dp[it]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}