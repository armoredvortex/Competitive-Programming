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
    ll n, m, h;
    cin >> n >> m >> h;

    vector<ll> original(n), current(n), timestamp(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> original[i];
        current[i] = original[i];
    }

    ll lastTimestamp = 0;
    for (ll i = 0; i < m; i++)
    {
        ll b, c;
        cin >> b >> c;
        b--;
        if (timestamp[b] < lastTimestamp)
        {
            current[b] = original[b];
        }
        if (current[b] + c > h)
        {
            current[b] = original[b];
            lastTimestamp = i;
        }
        else
        {
            current[b] += c;
        }
        timestamp[b] = i;
    }

    for (ll i = 0; i < n; i++)
    {
        if (timestamp[i] < lastTimestamp)
        {
            current[i] = original[i];
        }
    }

    for (auto e : current)
    {
        cout << e << ' ';
    }
    cout << '\n';
    // cout << current << '\n';
    //      << timestamp << "\n\n";
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