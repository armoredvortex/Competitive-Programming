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
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> v(n * n);
    for (ll i = 0; i < n * n; i++)
    {
        cin >> v[i];
    }

    sort(all(v));
    ll a11 = v[0];

    int matrix[n][n];
    matrix[0][0] = a11;
    for (ll i = 1; i < n; i++)
    {
        matrix[0][i] = matrix[0][i - 1] + d;
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j < n; j++)
        {
            matrix[j][i] = matrix[j - 1][i] + c;
        }
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < n; j++)
    //     {
    //         cout << matrix[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }
    // cout << '\n';

    map<ll, ll> mgot, m;

    for (auto e : v)
    {
        m[e]++;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            mgot[matrix[i][j]]++;
        }
    }

    for (auto e : mgot)
    {
        if (m[e.first] != e.second)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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