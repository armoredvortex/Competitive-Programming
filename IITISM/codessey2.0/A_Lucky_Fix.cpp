#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

ll digdiff(ll a, ll b)
{
    vector<ll> dig1, dig2;
    for (ll i = 0; i < 3; i++)
    {
        dig1.push_back(a % 10);
        dig2.push_back(b % 10);

        a /= 10;
        b /= 10;
    }

    ll diff = 0;
    for (ll i = 0; i < 3; i++)
    {
        if (dig1[i] != dig2[i])
        {
            diff++;
        }
    }
    return diff;
}

void solve()
{
    ll n;
    cin >> n;

    if (n % 7 == 0)
    {
        cout << n << '\n';
        return;
    }
    for (ll i = n - n % 10; i < n - n % 10 + 10; i++)
    {
        if (i % 7 == 0)
        {
            cout << i << '\n';
            return;
        }
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