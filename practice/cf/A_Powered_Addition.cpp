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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll mx = v[0];
    ll mj = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] < mx)
        {
            ll diff = mx - v[i];
            // cerr << diff;
            ll toadd = 0;
            for (ll j = 0; j < 60; j++)
            {
                toadd = toadd << 1;
                toadd++;
                // cerr << toadd << ' ' << diff << "\n";

                if (toadd >= diff)
                {
                    // v[i] += toadd;
                    mj = max(mj, j + 1);
                    break;
                }
            }
        }
        mx = max(mx, v[i]);
    }
    // cerr << v;
    cout << mj << '\n';
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