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

ll find_min(set<ll> &st, ll val)
{
    // cerr << st << '\n';

    auto e1 = st.lower_bound(val);
    if (e1 == st.begin())
    {
        return abs(val - *e1);
    }
    auto e2 = --e1;
    e1++;
    if (e1 == st.end())
    {

        return abs(val - *e2);
    }

    return min(abs(val - *e1), abs(val - *e2));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, q;
    cin >> n >> m >> q;

    vll a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    ll a_acc = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a_acc += a[i];
        }
        else
        {
            a_acc -= a[i];
        }
    }

    vll pre_b(m - n + 1);
    ll right = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            pre_b[0] += b[i];
        }
        else
        {
            pre_b[0] -= b[i];
        }
        right++;
    }
    for (ll i = 1; i < m - n + 1; i++)
    {
        pre_b[i] = pre_b[i - 1];
        pre_b[i] -= b[i - 1];
        right++;
        if (n % 2 == 0)
        {
            pre_b[i] += b[right - 1];
        }
        else
        {
            pre_b[i] -= b[right - 1];
        }
        pre_b[i] *= -1;
    }

    // cerr << pre_b;

    set<ll> st(pre_b.begin(), pre_b.end());
    cout << find_min(st, a_acc) << '\n';
    for (ll i = 0; i < q; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        l--, r--;

        ll sz = r - l + 1;
        if (l % 2 == 0 && sz % 2)
        {
            a_acc += x;
        }
        if (l % 2 && sz % 2)
        {
            a_acc -= x;
        }
        cout << find_min(st, a_acc) << '\n';
    }
}