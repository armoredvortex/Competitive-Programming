#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
// #include "debugging.h"
void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll q;
    cin >> q;

    vll pre(n);
    pre[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            pre[i] = pre[i - 1] + 1;
        }
        else
        {
            pre[i] = pre[i - 1];
        }
    }

    // cerr << pre;

    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (pre[l] == pre[r])
        {
            cout << "-1 -1\n";
        }
        else
        {
            cout << l + 1 << " " << lower_bound(pre.begin(), pre.end(), pre[l] + 1) - pre.begin() + 1 << '\n';
        }
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