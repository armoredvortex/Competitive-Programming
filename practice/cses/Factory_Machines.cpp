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

    ll n, x;
    cin >> n >> x;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll left = 0, right = 1e18 + 10;
    ll ans;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll ct = 0;
        for (auto e : v)
        {
            if (ct > x)
            {
                break;
            }
            ct += (mid / e);
        }

        if (ct < x)
        {
            left = mid + 1;
        }
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans << '\n';
}