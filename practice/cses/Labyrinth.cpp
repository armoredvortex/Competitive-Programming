#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

// #ifndef ONLINE_JUDGE
// #include "debugging.h"
// #endif

vector<vector<int>> visited;
string path, minp;
ll minsz = LONG_LONG_MAX;
ll n, m;
pair<int, int> startp, endp;

void dfs(int x, int y, vector<vector<char>> &arr)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }

    if (visited[x][y])
    {
        return;
    }
    if (arr[x][y] == 'B')
    {
        if (path.size() < minsz)
        {
            minp = path;
            minsz = path.size();
        }
        return;
    }
    visited[x][y] = 1;

    path += 'R';
    dfs(x, y + 1, arr);
    path.pop_back();

    path += 'L';
    dfs(x, y - 1, arr);
    path.pop_back();

    path += 'U';
    dfs(x - 1, y, arr);
    path.pop_back();

    path += 'D';
    dfs(x + 1, y, arr);
    path.pop_back();

    visited[x][y] = 0;

    return;
}

void solve()
{
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m, 0));
    visited.resize(n);
    for (ll i = 0; i < n; i++)
    {
        visited[i].resize(m, 0);
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                startp = {i, j};
            }
            if (arr[i][j] == 'B')
            {
                endp = {i, j};
            }
            if (arr[i][j] == '#')
            {
                visited[i][j] = 1;
            }
        }
    }

    // cerr << startp << ' ' << endp << '\n';
    // cerr << visited << '\n';

    dfs(startp.first, startp.second, arr);

    if (!minp.size())
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n"
             << minp.size() << '\n'
             << minp << '\n';
        return;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    while (t--)
        solve();
}