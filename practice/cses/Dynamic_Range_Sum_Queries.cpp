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

void update(vll &f, unsigned int i, int old, int nw)
{
    int diff = nw - old;
    while (i < f.size())
    {
        f[i] += diff;
        i += i & -i;
    }
}

ll query(vll &f, unsigned int i)
{
    ll ans = 0;
    while (i != 0)
    {
        ans += f[i];
        i -= i & -i;
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, q;
    cin >> n >> q;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vll fen(1 << 21, 0);
    for (int i = 0; i < n; i++)
    {
        update(fen, i + 1, 0, v[i]);
    }

    for (ll i = 0; i < q; i++)
    {
        ll qi, a, b;
        cin >> qi >> a >> b;
        if (qi == 1)
        {
            update(fen, a, v[a - 1], b);
            v[a - 1] = b;
        }
        else
        {
            cout << query(fen, b) - query(fen, a - 1) << '\n';
        }
    }
}