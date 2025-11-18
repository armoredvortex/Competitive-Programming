#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

// #include <debugging.h>

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    map<ll, vector<ll>> m;
    for (ll i = 0; i < n; i++)
    {
        m[v[i].first].push_back(v[i].second);
    }

    for (auto &e : m)
    {
        sort(e.second.rbegin(), e.second.rend());
    }

    map<ll, vector<ll>> suff;
    for (const auto &e : m)
    {
        vector<ll> s(e.second.size());
        s[0] = e.second[0];
        for (ll i = 1; i < e.second.size(); i++)
        {
            s[i] = s[i - 1] + e.second[i];
        }
        reverse(all(s));
        suff[e.first] = s;
    }

    // cerr << suff << '\n';
    // for (ll i = 1; i < n + 1; i++)
    // {
    //     ll ans = 0;
    //     for (const auto &e : suff)
    //     {
    //         if (e.second.size() < i)
    //         {
    //             continue;
    //         }
    //         ll nn = e.second.size() % i;
    //         ans += e.second[nn];
    //     }
    //     cout << ans << ' ';
    // }
    // cout << '\n';

    vll ans(n, 0);
    for (const auto &e : suff)
    {
        // cerr << e.second.size() << '\n';
        ll k = e.second.size();
        // cerr << k;
        for (ll i = 0; i < min(n, k); i++)
        {
            ll nn = e.second.size() % (i + 1);
            ans[i] += e.second[nn];
        }
    }

    for (const auto &e : ans)
    {

        cout << e << ' ';
    }
    cout << '\n';
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