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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll a = LONG_LONG_MAX, b = LONG_LONG_MAX;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        auto e = v[i];

        if (e > a && e > b)
        {
            if (a < b)
            {
                a = e;
            }
            else
            {
                b = e;
            }
            ans++;
            continue;
        }
        if (e > a && e <= b)
        {
            b = e;
            continue;
        }
        else if (e <= a && e > b)
        {
            a = e;
            continue;
        }

        if (a < b)
        {
            a = e;
        }
        else
        {
            b = e;
        }
    }
    cout << ans << '\n';
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
