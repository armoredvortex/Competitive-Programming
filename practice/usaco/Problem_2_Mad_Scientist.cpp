#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

// #ifndef ONLINE_JUDGE
// #include "debugging.h"
// #endif

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    ll n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            s.insert(i);
        }
    }

    // cerr << s << '\n';
    ll ans = 0;
    ll left = -1;
    for (auto e : s)
    {
        ll d = e - left - 1;
        ans += (d > 0) ? 1 : 0;
        left = e;
    }

    if (left != n - 1)
    {
        ans += 1;
    }
    cout << ans << '\n';
}