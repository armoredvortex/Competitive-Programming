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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    ll ct = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1)
            {
                ct++;
            }
        }
    }

    ll a = ct / 2, b = ct - a;

    ll ct2 = 0;
    ll x = 0, y = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                ct2++;
                if (ct2 == a)
                {
                    x = j;
                    y = i;
                }
            }
        }
    }
    cerr << x << ' ' << y << '\n';
    cout << a * b << '\n';
    for (ll i = 0; i < y; i++)
    {
        cout << 'D';
    }
    for (ll i = 0; i < x; i++)
    {
        cout << 'R';
    }
    cout << "RD";
    for (ll i = x + 1; i < m; i++)
    {
        cout << 'R';
    }
    for (ll i = y + 1; i < n; i++)
    {
        cout << 'D';
    }

    cout << '\n';
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