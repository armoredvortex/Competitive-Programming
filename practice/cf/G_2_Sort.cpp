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
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll vvv;
    vvv.push_back(0);
    for (ll i = 1; i < n; i++)
    {
        if (2 * v[i] <= v[i - 1])
        {

            vvv.push_back(i);
        }
    }
    vvv.push_back(n);

    ll ans = 0;
    for (ll i = 1; i < vvv.size(); i++)
    {
        ll diff = vvv[i] - vvv[i - 1];
        // cerr << diff << '\n';
        ans += max(0ll, diff - k);
    }

    cout << ans << '\n';
    // cerr << vvv << '\n';
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