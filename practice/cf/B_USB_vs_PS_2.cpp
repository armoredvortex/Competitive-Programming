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

    ll a, b, c;
    cin >> a >> b >> c;
    ll m;
    cin >> m;
    vector<pair<ll, string>> v(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
        // cout << v[i].first << ' ' << v[i].second;
    }

    sort(v.begin(), v.end());

    ll ct = 0, spent = 0;
    for (ll i = 0; i < m; i++)
    {
        if (a && v[i].second == "USB")
        {
            ct++;
            spent += v[i].first;
            a--;
        }
        else if (b && v[i].second == "PS/2")
        {
            ct++;
            spent += v[i].first;
            b--;
        }
        else if (c)
        {
            ct++;
            spent += v[i].first;
            c--;
        }
    }
    cout << ct << ' ' << spent;
}