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
    // cerr << distv << '\n';
    set<ll> visited;
    vector<vector<ll>> g(n);
    ll ec = 0;
    for (auto e : distv)
    {
        auto d = e[0], p1 = e[1], p2 = e[2];

        if (visited.find(p1) == visited.end() || visited.find(p2) == visited.end())
        {
            visited.insert(p1);
            visited.insert(p2);
            g[p1].push_back(p2);
            g[p2].push_back(p1);
            ec++;
        }
        else
        {
            set<ll> vv;
            stack<ll> s;
            s.push(p1);
            vv.insert(p1);
            // cerr << g << '\n';
            // cerr << p1 << ' ' << p2 << '\n';
            ll flag = 1;
            while (!s.empty())
            {

                auto f = s.top();
                cerr << f << '\n';
                s.pop();
                // vv.insert(f);
                for (auto ff : g[f])
                {
                    if (ff == p2)
                    {
                        flag = 0;
                        break;
                    }
                    if (vv.find(ff) == vv.end())
                    {
                        s.push(ff);
                        vv.insert(ff);
                    }
                }
            }
            if (flag)
            {
                visited.insert(p1);
                visited.insert(p2);
                g[p1].push_back(p2);
                g[p2].push_back(p1);
                ec++;
            }
        }

        if (ec == n - 1)
        {
            cerr << g << '\n';
            cout << e << '\n';
            // cout << v[e[0]] << ' ' << v[e[1]] << '\n';
            break;
        }
    }
}