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
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (k == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            ll a = v[i];
            if (a % 2 == 0)
            {
                cout << a << ' ';
            }
            else
            {
                cout << a + 1 << ' ';
            }
        }
        cout << '\n';
        return;
    }

    if (k == 2)
    {
        for (ll i = 0; i < n; i++)
        {
            ll a = v[i];
            if (a % 3 == 0)
            {
                cout << a << ' ';
            }
            else if (a % 3 == 1)
            {
                cout << a + 2 << ' ';
            }
            else
            {
                cout << a + 4 << ' ';
            }
        }
        cout << '\n';
        return;
    }

    for (ll i = 0; i < n; i++)
    {
        ll a = v[i];
        // ll e = (k - 1) - a;
        cout << a + k * ((k - 1) - a % (k - 1)) << ' ';
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