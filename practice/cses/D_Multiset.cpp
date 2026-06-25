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

void update(vll &fen, int i, int old, int nw)
{
    while (i < fen.size())
    {
        fen[i] += nw - old;
        i += i & -i;
    }
}

int query(vll &fen, int i)
{
    int ans = 0;
    while (i != 0)
    {
        ans += fen[i];
        i -= i & -i;
    }
    return ans;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vll v(n + 1, 0), fen(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        update(fen, a, v[a], v[a] + 1);
        v[a]++;
    }

    for (ll i = 0; i < q; i++)
    {
        ll qi;
        cin >> qi;
        if (qi > 0)
        {
            update(fen, qi, v[qi], v[qi] + 1);
            v[qi]++;
        }
        else
        {
            qi = abs(qi);
            int left = 1, right = n;
            int mid, ans = -1;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                int x = query(fen, mid);
                if (x > qi - 1)
                {
                    if (v[mid])
                    {
                        ans = mid;
                    }
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            // cerr << ans << ' ';
            update(fen, ans, v[ans], v[ans] - 1);
            v[ans] -= 1;
        }
    }
    vll ansv;
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    // int t;
    // cin >> t;
    // while (t--)
    solve();
}