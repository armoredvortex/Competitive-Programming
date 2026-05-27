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

// 4 12 24
// +4 +8 +12 +16
void solve()
{
    ll p, q;
    cin >> p >> q;

    ll total = p + 2 * q;
    for (int m = 1; m < 1e5; m++)
    {
        if ((total - m) % (1 + 2 * m) == 0)
        {
            ll n = (total - m) / (1 + 2 * m);

            if (p >= abs(m - n))
            {
                cout << m << ' ' << n << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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