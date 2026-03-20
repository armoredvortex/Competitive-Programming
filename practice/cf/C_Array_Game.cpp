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

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (k >= 3)
    {
        cout << 0 << '\n';
        return;
    }

    if (k == 1)
    {
        ll m = *min_element(v.begin(), v.end());
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                m = min(abs(v[j] - v[i]), m);
            }
        }
        cout << m << '\n';
        return;
    }
    else
    {
        vector<ll> diff;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                diff.push_back(abs(v[i] - v[j]));
            }
        }

        // cerr << diff;
        ll m = *min_element(v.begin(), v.end());
        m = min(*min_element(diff.begin(), diff.end()), m);
        for (auto e : diff)
        {
            auto k = lower_bound(v.begin(), v.end(), e);
            m = min(m, abs(*k - e));
            if (k - v.begin() > 0)
            {
                m = min(m, abs(*(k - 1) - e));
            }
        }
        cout << m << "\n";
    }
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