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
    int k;
    cin >> k;

    int oddE = false;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        if (v % 2 != 0)
        {
            oddE = 1;
        }
    }

    int m;
    cin >> m;

    ll s = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        s += v;
    }

    if (oddE)
    {
        cout << "Alice\n";
    }
    else
    {
        if (s % 2 == 0)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "\n";
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