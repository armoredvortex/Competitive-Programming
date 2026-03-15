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
    ll n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll val = v[p];
    ll ans = 0;
    while (m)
    {
        if (p < k)
        {
            if (m - val >= 0)
            {
                v.erase(v.begin() + p);
                v.push_back(val);
                p = n-1;
                ans++;
                m -= val;
                continue;
            }
        }

        auto e = min_element(v.begin(), v.begin() + k);
        ll temp = *e;
        // cerr << temp << '\n';
        if (m - *e >= 0)
        {
            v.erase(e);
            v.push_back(temp);
            p--;
            m -= temp;
        }
        else
        {
            break;
        }
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