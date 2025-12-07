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
    ll n = 141, m = 141;

    vector<vector<char>> v(n, vector<char>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }

    for (ll i = 0; i < v[0].size(); i++)
    {
        if (v[0][i] == 'S')
        {
            v[1][i] = '|';
        }
    }

    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == '.' && v[i - 1][j] == '|')
            {
                v[i][j] = '|';
            }
            if (v[i][j] == '^' && v[i - 1][j] == '|')
            {
                ans++;
                v[i][j - 1] = '|';
                v[i][j + 1] = '|';
            }
        }
    }

    cout << v;
    cout << ans;
}