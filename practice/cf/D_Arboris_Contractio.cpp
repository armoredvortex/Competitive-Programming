#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve()
{
    ll n;
    cin >> n;

    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 2)
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> isleaf(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            isleaf[i] = 1;
        }
    }

    vll ct(n, 0);
    for (ll i = 0; i < n; i++)
    {
        for (auto e : g[i])
        {
            if (isleaf[e])
            {
                ct[i]++;
            }
        }
    }

    cout << count(isleaf.begin(), isleaf.end(), 1) - *max_element(ct.begin(), ct.end()) << '\n';
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