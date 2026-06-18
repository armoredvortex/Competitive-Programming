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

ll sub2(vll &v, ll k, ll mx)
{
    map<ll, ll> mp;
    ll left = 0, right = 0;
    ll ans = 0;
    while (right < v.size())
    {
        mp[v[right]]++;
        while (mp.size() > k)
        {
            if (--mp[v[left]] == 0)
            {
                mp.erase(v[left]);
            }
            left++;
        }
        ans += min(right - left + 1, mx);
        right++;
    }
    return ans;
}

ll sub(vll &v, ll k, ll mx)
{
    if (mx == 0)
        return 0;

    return sub2(v, k, mx) - sub2(v, k - 1, mx);
}

void solve()
{
    ll n, k, l, r;
    cin >> n >> k >> l >> r;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << sub(v, k, r) - sub(v, k, l - 1) << '\n';
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