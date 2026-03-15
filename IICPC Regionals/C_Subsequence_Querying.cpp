#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool dfs(ll node, vector<vector<ll>> &adj, ll len, vector<ll> &trav)
{
    // for(auto e: t)
    if (trav.size() == len)
    {
        cout << "? " << trav.size() << ' ';
        for (auto e : trav)
        {
            cout << e << ' ';
        }
        cout << '\n';
        fflush(stdout);
        ll res;
        cin >> res;
        return res;
    }
    trav.push_back(node);
    for (auto f : adj[node])
    {
        if (dfs(f, adj, len, trav))
        {
            return true;
        }
    }
    trav.pop_back();
    return false;
}

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> edges;

    unordered_map<ll, ll> mp;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (edges.size() == n - 1)
            {
                break;
            }
            if (mp[100 * i + j] == -1)
            {
                continue;
            }
            cout << "? 2 " << i << ' ' << j << '\n';
            fflush(stdout);
            ll res;
            cin >> res;
            if (res)
            {
                mp[100 * i + j] == 1;
                ll flag = 1;
                for (ll k = 1; k <= n; k++)
                {
                    if (mp[100 * i + k] == -1 || mp[100 * k + j] == -1)
                    {
                        continue;
                    }
                    cout << "? 3 " << i << ' ' << k << ' ' << j << '\n';
                    fflush(stdout);
                    ll res2;
                    cin >> res2;
                    if (res2)
                    {
                        mp[100 * i + k] = 1;
                        mp[100 * k + j] = 1;
                        flag = 0;
                        break;
                    }
                    else
                    {
                        if (mp[100 * i + k] == 1)
                        {
                            mp[100 * k + j] = -1;
                        }
                        if (mp[100 * k + j] == 1)
                        {
                            mp[100 * i + j] = -1;
                        }
                    }
                }
                if (flag)
                {
                    edges.push_back({i, j});
                }
            }
            else
            {
                mp[100 * i + j] = -1;
            }
        }
    }

    // for (auto e : edges)
    // {
    //     cerr << e.first << '-' << e.second << '\n';
    // }
    vector<vector<ll>> adj(n + 1);
    for (auto e : edges)
    {
        adj[e.first].push_back(e.second);
    }

    for (ll i = 1; i <= n; i++)
    {
        vector<ll> trav;
        if (dfs(i, adj, n, trav))
        {
            cout << "! ";
            for (auto e : trav)
            {
                cout << e << ' ';
            }
            cout << '\n';
            fflush(stdout);
            return;
        }
    }
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}