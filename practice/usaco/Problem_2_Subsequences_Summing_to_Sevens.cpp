#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    ll n;
    cin >> n;
    vll v(n);
    vll pre(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        pre[i + 1] = pre[i];
        pre[i + 1] += v[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        for (ll j = i + 1; j < n + 1; j++)
        {
            ll sss = pre[j] - pre[i];
            if (sss % 7 == 0)
            {
                ans = max(ans, j - i);
            }
        }
    }
    // cerr << pre;
    cout << ans << '\n';
}