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
    ll n;
    cin >> n;
    vector<ll> v(n), even, odd;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v[i] = a;
        if (a % 2)
        {
            odd.push_back(a);
        }
        else
        {
            even.push_back(a);
        }
    }

    if (even.size() == 0 || odd.size() == 0)
    {
        for (auto e : v)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
    else
    {
        sort(all(v));
        for (auto e : v)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
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