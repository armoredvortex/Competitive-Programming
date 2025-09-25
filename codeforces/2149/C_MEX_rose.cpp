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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(all(v));
    ll ct = 0;
    for (int i = 0; i < k; i++)
    {
        if (!binary_search(all(v), i))
        {
            ct++;
        }
    }

    ll ct2 = count(all(v), k);
    cout << max(ct, ct2) << endl;
    // cout << ct2 << endl;
    return;
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