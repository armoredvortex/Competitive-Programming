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

struct RollbackUF
{
    vi e;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
    }

    RollbackUF uf = RollbackUF(n);

    set<set<ll>> edges;
    for (ll i = 0; i < n; i++)
    {
        uf.join(i, v[i]);
        edges.insert({i, v[i]});
    }

    vll indeg(n, 0);
    for (auto e : edges)
    {
        auto it = e.begin();
        ll x = *it;
        it++;
        ll y = *it;

        indeg[x]++;
        indeg[y]++;
    }

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[uf.find(i)].push_back(i);
    }

    ll total_components = mp.size();

    ll ct = 0;
    for (auto e : mp)
    {
        ll flag = 1;
        for (auto f : e.second)
        {
            if (indeg[f] < 2)
            {
                flag = 0;
            }
        }
        if (!flag)
        {
            ct++;
        }
    }

    cout << (ct ? total_components - ct + 1 : total_components) << ' ' << total_components << "\n";
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