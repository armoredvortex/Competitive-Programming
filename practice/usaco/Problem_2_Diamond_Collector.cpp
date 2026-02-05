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

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ll left = 0;
    ll right = 0;

    ll ans = 0;
    // for (auto e : v)
    // {
    //     cout << e << ' ';
    // }
    // cout << '\n';
    for (int i = 0; i < v.size() - 1; i++)
    {
        auto no = upper_bound(v.begin() + i + 1, v.end(), k + v[i]) - v.begin() - 1 - i;
        // cerr << v[i] << ' ' << no << '\n';
        ans += no;
    }

    cout << ans;
}