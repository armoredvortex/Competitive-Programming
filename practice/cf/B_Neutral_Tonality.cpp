#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

void solve()
{
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (ll i = 0; i < n; i++)
    {
        while (b.size() && b.back() >= a[i])
        {
            cout << b.back() << ' ';
            b.pop_back();
        }
        cout << a[i] << ' ';
    }
    while (b.size())
    {
        cout << b.back() << ' ';
        b.pop_back();
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
