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
    // cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);

    ll n, t, k;
    cin >> n >> t;
    cin >> k;

    ll left = 1, right = n;
    ll ans = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        cout << "? " << 1 << ' ' << mid << '\n';
        fflush(stdout);

        ll sum;
        cin >> sum;
        ll true_zeroes = mid - sum;
        if (true_zeroes < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            ans = mid;
        }
    }

    cout << "! " << ans << '\n';
    fflush(stdout);
}