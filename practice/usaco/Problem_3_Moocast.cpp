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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    ll n;
    cin >> n;

    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y, p;
        cin >> x >> y >> p;

        v[i] = {x, y, p};
    }

    vector<vector<ll>> g(n);
    for (ll i = 0; i < n; i++)
    {
        auto e1 = v[i];
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            auto e2 = v[j];

            ll d = (e1[0] - e2[0]) * (e1[0] - e2[0]) + (e1[1] - e2[1]) * (e1[1] - e2[1]);
            if (e1[2] * e1[2] >= d)
            {
                g[i].push_back(j);
            }
        }
    }

    ll ans = -1;

    for (ll i = 0; i < n; i++)
    {
        stack<ll> s;
        s.push(i);
        vector<ll> visited(n, 0);

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
                }
            }
        }

        ans = max(ans, (long long)count(visited.begin(), visited.end(), 1));
    }

    cout << ans << '\n';
}