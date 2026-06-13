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
    ll a, b, x;
    cin >> a >> b >> x;

    vector<pair<ll, int>> div_a, div_b;

    ll temp_a = a;
    ll ops = 0;
    while (true)
    {
        div_a.push_back({temp_a, ops});
        if (temp_a == 0)
            break;
        temp_a /= x;
        ops++;
    }

    ll temp_b = b;
    ops = 0;
    while (true)
    {
        div_b.push_back({temp_b, ops});
        if (temp_b == 0)
            break;
        temp_b /= x;
        ops++;
    }

    ll min_ops = -1;

    for (auto pa : div_a)
    {
        for (auto pb : div_b)
        {
            ll u = pa.first;
            ll v = pb.first;
            ll target = max(u, v);

            ll current_ops = pa.second + pb.second + (target - u) + (target - v);

            if (min_ops == -1 || current_ops < min_ops)
            {
                min_ops = current_ops;
            }
        }
    }

    cout << min_ops << '\n';
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