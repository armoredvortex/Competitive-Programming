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
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll x = v[j];
            ll y = v[i];
            vll seq = {x, y};
            for (ll k = 0; k < n - 2; k++)
            {
                ll h = seq[seq.size() - 2] % seq[seq.size() - 1];
                if (h == 0)
                {
                    break;
                }
                seq.push_back(h);
            }
            sort(seq.begin(), seq.end());
            if (v == seq)
            {
                cout << x << ' ' << y << '\n';
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