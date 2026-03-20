#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vll a(n), b(n);

    a[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    // sort(a.rbegin(), a.rend());
    // sort(b.rbegin(), b.rend());
    ll ans = 0;
    ll left = 0;
    for (ll i = 0; i < n; i++)
    {
        while (left < n && b[left] <= a[i])
        {
            left++;
        }

        if (left >= n)
        {
            break;
        }
        ans++;
        left++;
    }

    cout << n - ans << '\n';
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