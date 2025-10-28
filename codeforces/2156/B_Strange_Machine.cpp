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
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    if (s.find('B') == s.npos)
    {
        for (ll i = 0; i < q; i++)
        {
            ll a;
            cin >> a;
            cout << a << endl;
        }
        return;
    }
    for (ll i = 0; i < q; i++)
    {
        ll a;
        cin >> a;

        ll ans = 1;
        while (a)
        {
            for (ll i = 0; i < n; i++)
            {
                if (s[i] == 'A')
                {
                    a -= 1;
                }
                else if (s[i] == 'B')
                {
                    a /= 2;
                }

                if (a == 0)
                {
                    break;
                }
                ans++;
            }
        }
        cout << ans << endl;
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