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
    ll n, x;
    cin >> n >> x;

    ll ansl = n, ansr = LONG_LONG_MAX;
    for (ll i = 0; i < 63; i++)
    {
        ll mask = (1ll << i);
        if (!(n & mask) && (x & mask))
        {
            cout << -1 << '\n';
            return;
        }
        else if ((n & mask) && (x & mask))
        {
            ll left = n;
            ll right = n + (1ll << (i + 1)) - 1;
            ll mid, subans = left;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (mid & mask)
                {
                    subans = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            ansr = min(ansr, subans);
        }
        else if ((n & mask) && !(x & mask))
        {
            ll left = n;
            ll right = n + (1ll << (i + 1)) - 1;
            ll mid, subans = right;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (!(mid & mask))
                {
                    subans = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            ansl = max(ansl, subans);
        }
    }
    if (ansr < ansl)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ansl << '\n';
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