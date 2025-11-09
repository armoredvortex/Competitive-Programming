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
    ll n, l;
    cin >> n >> l;

    vector<double> a;
    a.push_back(0);
    for (ll i = 0; i < n; i++)
    {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }

    a.push_back(l);

    vector<double> ltime(n + 2);
    vector<ll> lsp(n + 2);
    lsp[0] = 1;
    double lspeed = 1;
    for (ll i = 1; i < n + 2; i++)
    {
        ltime[i] = ltime[i - 1] + (a[i] - a[i - 1]) / lspeed;
        lspeed++;
        lsp[i] = lspeed;
    }

    vector<ll> rsp(n + 2);
    rsp[n + 1] = 1;
    vector<double> rtime(n + 2);
    double rspeed = 1;
    for (ll i = 1; i < n + 2; i++)
    {
        rtime[n + 1 - i] = rtime[n + 2 - i] + (a[n - i + 2] - a[n - i + 1]) / rspeed;
        rspeed++;
        rsp[n + 1 - i] = rspeed;
    }

    // for (auto e : lsp)
    // {
    //     cout << e << ' ';
    // }
    // cout << '\n';
    // for (auto e : ltime)
    // {
    //     cout << e << ' ';
    // }
    // cout << '\n';

    // for (auto e : rsp)
    // {
    //     cout << e << ' ';
    // }
    // cout << '\n';
    // for (auto e : rtime)
    // {
    //     cout << e << ' ';
    // }
    // cout << '\n';

    // for (ll i = 0; i < ltime.size(); i++)
    // {
    //     if (ltime[i] == rtime[i])
    //     {
    //         cout << ltime[i] << '\n';
    //         return;
    //     }
    // }

    ll lbound, rbound;
    for (ll i = 0; i < ltime.size(); i++)
    {
        if (ltime[i] >= rtime[i])
        {
            lbound = i;
            break;
        }
    }

    for (ll i = 0; i < ltime.size(); i++)
    {
        if (rtime[i] >= ltime[i])
        {
            rbound = i;
        }
    }

    // cout << ltime[rbound] << ' ' << rtime[lbound] << '\n';

    double dist = a[lbound] - a[rbound];
    double vrel = lsp[rbound] + rsp[lbound];

    if (ltime[rbound] > rtime[lbound])
    {
        double dt = ltime[rbound] - rtime[lbound];
        dist -= rsp[lbound] * dt;

        cout << fixed << setprecision(10);
        cout << (ltime[rbound] + dist / vrel) << endl;
    }
    else
    {
        double dt = rtime[lbound] - ltime[rbound];
        dist -= lsp[rbound] * dt;

        cout << fixed << setprecision(10);

        cout << (rtime[lbound] + dist / vrel) << endl;
    }
    // cout << vrel << '\n';

    // cout << dist << '\n';
    // cout << lbound << '#' << rbound << '\n';
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