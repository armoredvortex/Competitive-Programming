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

bool wins(int i, int j, vector<vector<int>> &v)
{
    int ct = 0;
    for (int k = 0; k < 5; k++)
    {
        if (v[i][k] < v[j][k])
        {
            ct++;
        }
    }
    return ct >= 3;
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }
    }
    int winner = 0;
    for (int i = 1; i < n; i++)
    {
        if (!wins(winner, i, v))
        {
            winner = i;
        }
    }

    // cerr << winner + 1 << '\n';

    for (int i = 0; i < n; i++)
    {
        if (i != winner)
        {
            if (!wins(winner, i, v))
            {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << winner + 1 << '\n';
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