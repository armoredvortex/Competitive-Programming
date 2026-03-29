// (h*(n+1) + c*n)/2n == t

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
    ll h, c, t;

    cin >> h >> c >> t;

    ll mn;
    float mndiff = LONG_LONG_MAX;
    for (ll i = 1; i < 10; i++)
    {
        float diff = abs(t - (h * ((i + 1) / 2) + c * ((i / 2))) / (1.0 * i));
        // cerr << i << ' ' << diff << '\n';
        if (diff < mndiff)
        {
            mn = i;
            mndiff = diff;
        }
    }
    cout << mn << '\n';
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