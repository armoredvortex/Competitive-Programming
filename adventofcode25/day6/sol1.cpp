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

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[j][i];
        }
    }

    // cerr << v << '\n';

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        ll sub = v[i][0];
        if (c == '+')
        {
            for (ll j = 1; j < m; j++)
            {
                sub += v[i][j];
            }
        }
        else if (c == '*')
        {
            for (ll j = 1; j < m; j++)
            {
                sub *= v[i][j];
            }
        }

        // cerr << sub << '\n';
        ans += sub;
    }
    cout << ans << '\n';
}
