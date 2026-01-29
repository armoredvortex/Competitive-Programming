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

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll k = 0;
    vector<ll> posv;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            posv.push_back(i);
            k++;
        }
    }

    if (k == 0)
    {
        cout << (n + 2) / 3 << '\n';
        return;
    }

    ll ans = 0;
    if (posv.size() > 1)
    {
        for (int i = 0; i < posv.size() - 1; i++)
        {
            ll diff = posv[i + 1] - posv[i] - 1;
            // diff--;
            if (diff >= 3)
                ans += (diff) / 3;

            // cerr << diff << "\n";
        }
    }

    int first = posv[0];
    ll pref = (first+1) / 3;

    int last = posv.back();
    ll suff = (n - last) / 3;

    cout << k + ans + pref + suff << '\n';
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