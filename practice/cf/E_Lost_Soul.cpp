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
    vll a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    map<ll, ll> track1, track2;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            track1[a[i]] = i + 1;
            track2[b[i]] = i + 1;
        }
        else
        {
            track1[b[i]] = i + 1;
            track2[a[i]] = i + 1;
        }
    }
    ll ans = 0;
    // cerr << track1 << '\n'
    //      << track2 << '\n';
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (track2[a[i]] > i || track1[a[i]] > i + 2)
            {
                ans = max(ans, i + 1);
            }
            if (track1[b[i]] > i || track2[b[i]] > i + 2)
            {
                ans = max(ans, i + 1);
            }
        }
        else
        {
            if (track1[a[i]] > i || track2[a[i]] > i + 2)
            {
                ans = max(ans, i + 1);
            }
            if (track2[b[i]] > i || track1[b[i]] > i + 2)
            {
                ans = max(ans, i + 1);
            }
        }
    }
    cout << ans << '\n';
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