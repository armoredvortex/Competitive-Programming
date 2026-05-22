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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll mods(n);
    for (ll i = 0; i < n; i++)
    {
        mods[i] = v[i] % 10;
    }

    vll parity(n);
    for (ll i = 0; i < n; i++)
    {
        parity[i] = (v[i] / 10) % 2;
    }

    if (mods[0] == 0)
    {
        for (ll i = 0; i < n; i++)
        {
            if (v[i] != v[0])
            {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }
    else if (mods[0] == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (mods[i] == 1)
            {
                if (v[i] != v[0])
                {
                    cout << "NO\n";
                    return;
                }
            }  
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