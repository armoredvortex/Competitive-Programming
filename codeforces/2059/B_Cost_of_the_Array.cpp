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
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == k)
    {
        vll b;
        for (ll i = 1; i < n; i += 2)
        {
            b.push_back(v[i]);
        }

        for (ll i = 0; i < b.size(); i++)
        {
            if (b[i] != i + 1)
            {
                cout << i + 1 << '\n';
                return;
            }
        }
        cout << b.size() + 1 << '\n';
        return;
    }

    ll extra = n - k;
    for (ll i = 1; i < extra + 2; i++)
    {
        if (v[i] != 1)
        {
            cout << 1 << '\n';
            return;
        }
    }

    cout << "2\n";
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

// 6 6 x 1 x 2 x 3

//     6 4 x 1 1 1 x 2

//     6 2 x 1 1 1 1 1 1

//     8 8 x 1 x 2 x 3 x 4

//     8 6 x 1 1 1 x


// 1
// 7 6
// 7 1 1 2 3 4 5


// 7| 1 1 | 2 | 3 | 4 | 5
// 7 1 | 1 | 2 | 3 | 4 | 5