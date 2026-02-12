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
    ll n;
    cin >> n;

    vll p(n), a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll pptr = 0, aptr = 0;
    while (aptr < n)
    {
        if (p[pptr] != a[aptr])
        {
            pptr++;
            if (pptr >= n)
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            aptr++;
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