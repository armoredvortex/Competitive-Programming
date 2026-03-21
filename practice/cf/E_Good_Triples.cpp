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

ll digits(ll n)
{

    ll ans = 0;
    while (n)
    {
        n /= 10;
        ans++;
    }

    return ans;
}

void solve()
{
    ll n;
    cin >> n;

    ll d = digits(n);

    ll ans = 1;
    for (ll i = 0; i < d; i++)
    {
        ll cnt = 0;
        for (ll j = 0; j < 10; j++)
        {
            for (ll k = 0; k < 10; k++)
            {
                for (ll l = 0; l < 10; l++)
                {
                    if (j + k + l == (int)(n / pow(10, i)) % 10)
                    {
                        cnt++;
                    }
                }
            }
        }
        ans *= cnt;
    }
    cout << ans << '\n';
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