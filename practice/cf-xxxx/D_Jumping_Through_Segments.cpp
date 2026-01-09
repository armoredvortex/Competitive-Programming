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
    ll n;
    cin >> n;

    ll ans = 0;
    ll prev = 0, pl = 0, pr = 0;
    for (ll i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;

        if (prev >= l && prev <= r)
        {
            continue;
        }
        else if (prev > r)
        {
        }
        else
        {
        }
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