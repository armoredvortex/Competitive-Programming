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

    vector<vector<char>> v(n + 2, vector<char>(m + 2, '#'));
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, true));

    // cerr << v;

    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < m + 1; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == '.')
            {
                visited[i][j] = false;
            }
        }
    }

    // cerr << v << '\n\n';
    // cerr << visited << '\n';

    ll ans = 0;
    for (ll i = 0; i < n + 2; i++)
    {
        for (ll j = 0; j < m + 2; j++)
        {
            if (visited[i][j])
            {
                continue;
            }

            stack<pair<ll, ll>> s;
            s.push({i, j});
            while (!s.empty())
            {
                auto e = s.top();
                s.pop();
                visited[e.first][e.second] = true;

                if (!visited[e.first + 1][e.second])
                {
                    s.push({e.first + 1, e.second});
                }

                if (!visited[e.first][e.second + 1])
                {
                    s.push({e.first, e.second + 1});
                }

                if (!visited[e.first - 1][e.second])
                {
                    s.push({e.first - 1, e.second});
                }

                if (!visited[e.first][e.second - 1])
                {
                    s.push({e.first, e.second - 1});
                }
            }

            // cerr << visited << "\n\n";
            ans++;
        }
    }
    cout << ans << '\n';
}