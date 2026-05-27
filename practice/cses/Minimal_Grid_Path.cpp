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

    ll n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string ans;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {
        char mn = 'Z';
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto e = q.front();
            mn = min(mn, v[e.first][e.second]);
            q.pop();
            q.push(e);
        }
        ans += mn;
        for (int i = 0; i < sz; i++)
        {
            auto e = q.front();
            q.pop();
            // if (e.first == n - 1 && e.second == n - 1)
            // {
            //     cout << ans;
            //     return 0;
            // }
            if (v[e.first][e.second] == mn)
            {
                if (e.first + 1 < n)
                {
                    if (!visited[e.first + 1][e.second])
                    {
                        visited[e.first + 1][e.second] = 1;
                        q.push({e.first + 1, e.second});
                    }
                }
                if (e.second + 1 < n)
                {
                    if (!visited[e.first][e.second + 1])
                    {
                        visited[e.first][e.second + 1] = 1;
                        q.push({e.first, e.second + 1});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}