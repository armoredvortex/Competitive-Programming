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

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ll n;
    cin >> n;

    vector<char> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> pre(n + 1, vector<ll>(3, 0)), post(n + 1, vector<ll>(3, 0));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            pre[i + 1][j] = pre[i][j];
        }

        if (v[i] == 'P')
        {
            pre[i + 1][0]++;
        }
        else if (v[i] == 'H')
        {
            pre[i + 1][1]++;
        }
        else
        {
            pre[i + 1][2]++;
        }
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j < 3; j++)
        {
            post[i][j] = post[i + 1][j];
        }

        if (v[i] == 'P')
        {
            post[i][0]++;
        }
        else if (v[i] == 'H')
        {
            post[i][1]++;
        }
        else
        {
            post[i][2]++;
        }
    }

    ll ans = -1;
    for (ll i = 0; i < n + 1; i++)
    {
        ll msub = -1;
        for (ll j = 0; j < 3; j++)
        {
            for (ll k = 0; k < 3; k++)
            {
                ll sub = pre[i][j] + post[i][k];
                msub = max(msub, sub);
            }
        }
        ans = max(ans, msub);
    }
    cout << ans << '\n';
}