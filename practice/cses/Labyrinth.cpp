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

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<char>> prev(n, vector<char>(m, 0));
    pair<int, int> start, finish;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                start = {i, j};
                prev[i][j] = -1;
            }
            else if (v[i][j] == 'B')
            {
                finish = {i, j};
            }
            else if (v[i][j] == '#')
            {
                prev[i][j] = -1;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);

    int flag = 1;
    while (!q.empty())
    {
        if (!flag)
        {
            break;
        }
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto e = q.front();
            q.pop();
            if (e == finish)
            {
                flag = 0;
                break;
            }
            if (e.first + 1 < n && prev[e.first + 1][e.second] == 0)
            {
                prev[e.first + 1][e.second] = 'D';
                q.push({e.first + 1, e.second});
            }
            if (e.first - 1 >= 0 && prev[e.first - 1][e.second] == 0)
            {
                prev[e.first - 1][e.second] = 'U';
                q.push({e.first - 1, e.second});
            }
            if (e.second + 1 < m && prev[e.first][e.second + 1] == 0)
            {
                prev[e.first][e.second + 1] = 'R';
                q.push({e.first, e.second + 1});
            }
            if (e.second - 1 >= 0 && prev[e.first][e.second - 1] == 0)
            {
                prev[e.first][e.second - 1] = 'L';
                q.push({e.first, e.second - 1});
            }
        }
    }

    if (flag)
    {
        cout << "NO\n";
        return 0;
    }
    string ans;
    pair<int, int> it = finish;
    while (it != start)
    {
        // cerr << it << '\n';
        char c = prev[it.first][it.second];
        ans += c;
        if (c == 'U')
        {
            it.first++;
        }
        else if (c == 'D')
        {
            it.first--;
        }
        else if (c == 'R')
        {
            it.second--;
        }
        else if (c == 'L')
        {
            it.second++;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << '\n';
    cout << ans;
    return 0;
}