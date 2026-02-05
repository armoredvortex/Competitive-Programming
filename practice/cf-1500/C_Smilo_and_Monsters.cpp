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

    sort(v.begin(), v.end());

    ll left = 0, right = n - 1;
    ll x = 0;
    ll ans = 0;
    while (left < right)
    {
        // cout << x + v[left] << ' ' << v[right] << '\n';
        if (x + v[left] < v[right])
        {
            x += v[left];
            ans += v[left];
            v[left] = 0;
            left++;
        }
        else
        {
            v[left] -= v[right] - x;
            ans += v[right] - x;

            if (v[left] == 0)
            {
                left++;
            }

            x = 0;
            v[right] = 0;
            right--;
            ans++;
        }
    }
    if (v[left])
    {
        // cerr << x << ' ' << v[left] << ' ' << ans << '\n';
        ll excess = v[left] - x;
        if (excess % 2 == 0)
        {
            x += excess / 2;
            ans += excess / 2;
            v[left] -= excess / 2;
        }
        else
        {
            x += (excess + 1) / 2;
            ans += (excess + 1) / 2;
            v[left] -= (excess + 1) / 2;
        }
        if (v[left] > 0)
        {
            ans++;
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
