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
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v[i] = {x, y};
    }

    vector<vector<int>> mp(n);
    for (int i = 0; i < n; i++)
    {
        auto e = v[i];
        mp[e.first].push_back(i);
        mp[e.second].push_back(i);
    }

    vector<set<int>> adj(n);
    for (auto e : mp)
    {
        if (e.size() > 2)
        {
            cout << "NO\n";
            return;
        }
        if (e.size() == 2)
        {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
    }

    // cerr << adj << '\n';
    // for (auto e : adj)
    // {
    //     cerr << e << '\n';
    // }
    // cerr << '\n';

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] != -1)
        {
            continue;
        }
        stack<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty())
        {
            auto e = q.top();
            q.pop();

            for (auto f : adj[e])
            {
                if (color[f] == color[e])
                {
                    // cerr << e << ' ' << f << '\n';
                    cout << "NO\n";
                    return;
                }
                if (color[f] == -1)
                {
                    q.push(f);
                    color[f] = color[e] ^ 1;
                }
            }
        }
    }
    // cerr << color << '\n';

    cout << "YES\n";
    // cerr << mp << '\n';
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