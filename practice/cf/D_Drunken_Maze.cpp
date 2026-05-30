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

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<ll, ll> st, fin;
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (grid[i][j] == 'T')
            {
                fin = {i, j};
            }
            else if (grid[i][j] == '#')
            {
                vis[i][j] = 1;
            }
        }
    }

    queue<vector<ll>> q;
    q.push({st.first, st.second, 'X', 0, 0});
    vis[st.first][st.second] == 0;
    ll flag = 0;
    while (!q.empty())
    {
        if (flag)
        {
            break;
        }
        ll sz = q.size();
        for (ll i = 0; i < sz; i++)
        {
            auto e = q.front();
            q.pop();
            
        }
    }
}