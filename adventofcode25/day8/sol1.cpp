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

double ddist(vector<ll> &b1, vector<ll> &b2)
{
    return sqrt(1.0 * ((b1[0] - b2[0]) * (b1[0] - b2[0]) + (b1[1] - b2[1]) * (b1[1] - b2[1]) + (b1[2] - b2[2]) * (b1[2] - b2[2])));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
    {

        ll x, y, z;
        cin >> x >> y >> z;

        v[i] = {x, y, z};
    }

    vector<vector<double>> distv;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            vector<double> subd;
            subd.push_back(ddist(v[i], v[j]));
            subd.push_back(i);
            subd.push_back(j);
            distv.push_back(subd);
        }
    }

    sort(all(distv));

    // cerr << distv.size() << "\n";
    // cerr << v[distv[0][1]] << ' ' << v[distv[0][2]] << '\n';

    vector<vector<ll>> g(n);

    for (ll i = 0; i < m; i++)
    {
        auto e = distv[i];

        g[e[1]].push_back(e[2]);
        g[e[2]].push_back(e[1]);
    }
    // cerr << g;

    vector<ll> visited(n, 0);
    vector<ll> sizes;
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        stack<ll> s;
        s.push(i);
        ll sz = 1;
        while (!s.empty())
        {
            auto e = s.top();
            s.pop();

            visited[e] = 1;
            for (auto f : g[e])
            {
                if (!visited[f])
                {
                    s.push(f);
                    sz++;
                    visited[f] = 1;
                }
            }
        }
        sizes.push_back(sz);
    }

    sort(sizes.rbegin(), sizes.rend());
    cerr << sizes << '\n';

    cout << "\nAns:\n"
         << sizes[0] * sizes[1] * sizes[2]
         << '\n';
}