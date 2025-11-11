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

vector<pair<int, int>> ans;

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll mind = n;
    ll maxd = n * (n + 1) / 2;

    if (m < mind || m > maxd)
    {
        cout << -1 << '\n';
        return;
    }

    ll d = m - mind;

    ll k = n;

    vll ans;
    set<ll> s;
    while (d - (k - 1) > 0)
    {
        d -= k - 1;

        s.insert(k);
        ans.push_back(k);

        k--;
    }

    s.insert(d + 1);
    ans.push_back(d + 1);
    for (ll i = 1; i <= n; i++)
    {
        if (s.find(i) == s.end())
        {
            ans.push_back(i);
        }
    }

    // cerr << d << ' ' << k << '\n';
    // cerr << ans << '\n';

    cout << ans[0] << '\n';
    for (ll i = 0; i < n - 1; i++)
    {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
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