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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll nnn;
    cin >> nnn;

    string s;
    cin >> s;

    ll p = count(s.begin(), s.end(), '+');
    ll n = count(s.begin(), s.end(), '-');

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;

        ll k = lcm(a, b) / a;
        ll j = lcm(a, b) / b;

        if (max(p, n) % max(k, j) == 0 && min(p, n) % min(k, j) == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}