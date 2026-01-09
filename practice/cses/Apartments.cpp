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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> pref(n);

    multiset<ll> s;

    for (ll i = 0; i < n; i++)
    {
        cin >> pref[i];
    }

    for (ll i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }

    sort(pref.begin(), pref.end());

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll l = pref[i] - k, r = pref[i] + k;

        if (l != r)
        {
            auto e1 = s.lower_bound(l);
            auto e2 = s.upper_bound(r);

            if (e1 != e2)
            {
                ans++;
                s.erase(e1);
            }
        }
        else
        {
            auto e1 = s.lower_bound(l);
            if (*e1 == l)
            {
                ans++;
                s.erase(e1);
            }
        }
    }

    cout << ans;
}