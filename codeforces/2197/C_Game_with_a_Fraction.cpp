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
    ll p, q;
    cin >> p >> q;

    ll diff = q - p;
    if (diff <= 0)
    {
        cout << "Alice\n";
        return;
    }

    ll mink = diff * 2;

    if (p >= mink)
    {
        cout << "Bob\n";
        return;
    }
    else
    {
        cout << "Alice\n";
        return;
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