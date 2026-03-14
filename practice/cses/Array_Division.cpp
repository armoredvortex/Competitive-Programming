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

    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll left = *max_element(v.begin(), v.end()), right = accumulate(v.begin(), v.end(), 0ll);
    ll ans = right;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        ll ct = 1;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            auto e = v[i];
            if (sum + e > mid)
            {
                sum = e;
                ct++;
            }
            else
            {
                sum += e;
            }
        }

        // cerr << mid << ' ' << ct << '\n';

        if (ct <= k)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
}