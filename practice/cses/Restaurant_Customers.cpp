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

    vector<ll> a(n), b(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    sort(all(a));
    sort(all(b));

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        auto e = a[i];
        ll f = upper_bound(b.begin(), b.end(), e) - b.begin();

        ans = max(ans, i + 1 - f);
    }

    cout << ans << '\n';
}