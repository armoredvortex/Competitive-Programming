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
    double px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    double dist = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll mx = v[0], mn = v[0];
    for (ll i = 1; i < n; i++)
    {
        if (mx - v[i] >= 0 && mn - v[i] < 0)
        {
            mn = 0;
        }
        else
        {
            mn = min(abs(mx - v[i]), abs(mn - v[i]));
        }
        mx += v[i];
    }

    if (dist <= mx && dist >= mn)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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