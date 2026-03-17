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
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[i] = {y, x};
    }
    sort(v.begin(), v.end());

    ll left = 0, right = n - 1;
    ll ans = -1;
    while (left <= right)
    {
        ans = max(v[left].first + v[right].first, ans);

        ll pairs = min(v[left].second, v[right].second);
        v[left].second -= pairs;
        if (left != right)
            v[right].second -= pairs;

        if (v[left].second == 0)
        {
            left++;
        }
        if (v[right].second == 0)
        {
            right--;
        }
    }
    cout << ans << '\n';
}