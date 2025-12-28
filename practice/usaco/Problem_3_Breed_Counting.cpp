#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
     ll n, q;
    cin >> n >> q;

    vector<ll> a(n + 1, 0), b(n + 1,0), c(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        ll u;
        cin >> u;

        a[i + 1] = a[i];
        b[i + 1] = b[i];
        c[i + 1] = c[i];

        if (u == 1)
        {
            a[i + 1]++;
        }
        else if (u == 2)
        {
            b[i + 1]++;
        }
        else
        {
            c[i + 1]++;
        }
    }

    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;

        cout << a[r] - a[l-1] << ' ' << b[r] - b[l-1] << ' ' << c[r] - c[l-1] << '\n';
    }
}