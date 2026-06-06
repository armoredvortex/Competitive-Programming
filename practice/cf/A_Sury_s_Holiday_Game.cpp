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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());

    ll ascr = 0;
    ll bscr = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (v[i] % 2 == 0)
            {
                ascr += v[i];
            }
        }
        else
        {
            if (v[i] % 2 != 0)
            {
                bscr += v[i];
            }
        }
    }

    if (ascr > bscr)
    {
        cout << "Alice\n";
    }
    else if (bscr > ascr)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Tie\n";
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