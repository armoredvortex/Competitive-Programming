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

    ll n, a, b;
    cin >> n >> a >> b;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll prefix(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + v[i];
    }

    multiset<ll> mp;
    ll ans = accumulate(v.begin(), v.begin() + a, 0ll);
    // cerr << prefix;
    for (ll i = 1; i < n + 1; i++)
    {
        if (i - a >= 0)
        {
            mp.insert(prefix[i - a]);
            if (i - b - 1 >= 0)
            {
                mp.erase(mp.find(prefix[i - b - 1]));
            }
            ans = max(ans, prefix[i] - *mp.begin());
        }
    }

    cout << ans;
}