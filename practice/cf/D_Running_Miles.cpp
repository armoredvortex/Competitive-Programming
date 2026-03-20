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

    vll l(n), r(n);
    for (ll i = 0; i < n; i++)
    {
        l[i] = v[i] + i + 1;
        r[i] = v[i] - (i + 1);
    }

    ll ans = -1;

    vll pre(n), post(n);
    pre[0] = l[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = max(l[i], pre[i - 1]);
    }
    post[n - 1] = r[n - 1];
    for (ll i = 1; i < n; i++)
    {
        post[n - i - 1] = max(r[n - i - 1], post[n - i]);
    }

    // cerr << l << '\n'
    //      << r << '\n';
    // cerr << pre << '\n'
    //      << post;
    for (ll i = 1; i < n - 1; i++)
    {
        ans = max(pre[i - 1] + v[i] + post[i + 1], ans);
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