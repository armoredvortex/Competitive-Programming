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
    vector<vector<ll>> g(n);

    vll color(n);
    ll root;
    for (ll i = 0; i < n; i++)
    {
        ll v, c;
        cin >> v >> c;
        if (v == -1)
        {
            root = i;
            continue;
        }
        v--;
        g[i].push_back(v);
        g[v].push_back(i);
        color[i] = c;
    }

    stack<ll> s;
    s.push(root);
    vll visited(n, 0);

    vll ans;
    while (!s.empty())
    {
        auto e = s.top();
        s.pop();
        visited[e] = 1;

        int flag = 1;
        for (auto f : g[e])
        {
            if (!visited[f])
            {
                s.push(f);
            }
        }

        if (color[e] == 0)
        {
            continue;
        }

        for (auto f : g[e])
        {
            if (!visited[f])
            {
                if (color[f] == 0)
                {
                    flag = 0;
                }
            }
        }

        if (flag)
        {
            ans.push_back(e);
        }
    }

    // cerr << color;
    // cerr << g;

    sort(all(ans));
    if (ans.size() == 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (auto e : ans)
    {
        cout << e + 1 << ' ';
    }
    cout << '\n';
}