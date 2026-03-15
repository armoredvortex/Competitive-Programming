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

    ll n;
    cin >> n;

    ll left = 1, right = n * n;
    ll ans;
    ll k = (n * n) / 2;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        ll ct = 0;
        for (ll i = 0; i < n; i++)
        {
            ct += min(n, (mid - 1) / (i + 1));
        }

        if (ct > k)
        {
            right = mid - 1;
        }
        else
        {
            ans = mid;
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}