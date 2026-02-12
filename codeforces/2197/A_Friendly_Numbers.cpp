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

ll digsum(ll x)
{
    ll sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
void solve()
{
    ll x;
    cin >> x;

    ll ans = 0;
    for (ll i = x; i < x + 1000; i++)
    {
        if (i - digsum(i) == x)
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return;
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