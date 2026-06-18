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

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    while (s.size() < k)
    {
        s += s;
    }
    string t;
    for (ll i = 0; i < n; i++)
    {
        ll flag = 0;
        t += s[i];
        string k;
        while (k.size() < s.size())
        {
            k += t;
        }
        for (ll j = 0; j < s.size(); j++)
        {
            if (k[j] < s[j])
            {
                flag = 1;
                break;
            }
            if (s[j] < k[j])
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    while (t.size() < k)
    {
        t += t;
    }
    cout << t.substr(0, k) << '\n';
    // cerr << t << '\n';
}