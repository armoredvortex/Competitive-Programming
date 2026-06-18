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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        a--;
        v[a]++;
    }

    ll left = 0, right = 1e12;
    ll mid, ans = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        ll ct = 0;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] > mid)
            {
                ct += (v[i] - mid);
            }
            else
            {
                ct -= (mid - v[i]) / 2;
            }
        }
        if (ct <= 0)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
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