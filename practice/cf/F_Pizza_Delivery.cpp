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
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    map<ll, vector<ll>> mp;
    mp[ax].push_back(ay);
    mp[bx].push_back(by);
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    x.push_back(bx);
    for (ll i = 0; i < n; i++)
    {
        ll yi;
        cin >> yi;
        mp[x[i]].push_back(yi);
    }
    ll ans = 0;
    vector<pair<ll, ll>> vp;

    for (auto &e : mp)
    {
        sort(e.second.begin(), e.second.end());
        ans += e.second.back() - e.second[0];
        vp.push_back({e.second[0], e.second.back()});
    }
    ll prevx = ax;
    ll xdisp = 0;
    for (ll i = 0; i < x.size(); i++)
    {
        xdisp += x[i] - prevx;
        prevx = x[i];
    }

    // cerr << ans << '\n';
    // cerr << mp << '\n';
    // cerr << vp << '\n';
    vector<vector<ll>> dp(vp.size(), vector<ll>(2));
    dp[1][0] = abs(vp[0].first - vp[1].first);
    dp[1][1] = abs(vp[0].second - vp[1].second);
    for (ll i = 2; i < vp.size(); i++)
    {
        dp[i][0] = min(abs(vp[i - 1].first - vp[i].first) + dp[i - 1][1], abs(vp[i - 1].second - vp[i].first) + dp[i - 1][0]);
        dp[i][1] = min(abs(vp[i - 1].second - vp[i].second) + dp[i - 1][0], abs(vp[i - 1].first - vp[i].second) + dp[i - 1][1]);
        // dp[i][0] = dp[i - 1][1] + abs(vp[i - 1].first - vp[i].first);
        // dp[i][1] = dp[i - 1][0] + abs(vp[i - 1].second - vp[i].second);
    }
    // cerr << vp << '\n';
    // cerr << dp << '\n';
    // cerr << xdisp << ' ' << ans << ' ' << min(dp.back()[0], dp.back()[1]) << "\n\n";
    cout << xdisp + ans + min(dp.back()[0], dp.back()[1]) << '\n';
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