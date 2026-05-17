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
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;

    if (n == 2 || n == 3)
    {
        cout << 1 << '\n';
        return;
    }

    int dist = min((n + x1 - x2) % n, (n + x2 - x1) % n);
    cout << dist + k << '\n';
    
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