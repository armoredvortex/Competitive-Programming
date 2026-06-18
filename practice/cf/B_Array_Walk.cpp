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
    ll n, k, z;
    cin >> n >> k >> z;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vll pre(n + 1, 0);
    for (ll i = 1; i < n + 1; i++)
    {
        pre[i] = pre[i - 1] + v[i - 1];
    }
    ll ans = 0;
    // cerr << pre << '\n';
    for (ll i = 1; i < n; i++)
    {
        ll kcpy = k;
        ll score = 0;
        score += pre[i + 1];
        kcpy -= i;
        ll idx = i;
        ll ct = 0;
        while (ct != z && kcpy)
        {
            idx--;
            score += v[idx];
            kcpy--;
            ct++;

            if (kcpy)
            {
                idx++;
                score += v[idx];
                kcpy--;
            }
        }

        score += pre[idx + kcpy + 1] - pre[idx + 1];
        // cerr << score << '\n';
        if (kcpy >= 0)
            ans = max(ans, score);
    }
    cout << ans << '\n';
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