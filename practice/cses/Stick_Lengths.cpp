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

    vector<ll> v(n + 1);
    v[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i + 1];
    }

    sort(all(v));

    ll ans = accumulate(v.begin(), v.end(), 0ll);
    // cerr << v << '\n';
    for (ll i = 1; i < n + 1; i++)
    {
        // cerr << ans << '\n';
        ll d = v[i] - v[i - 1];
        ans = min(ans, ans + d * (i - 1) - d * (n - i + 1));
    }

    cout << ans << '\n';
}