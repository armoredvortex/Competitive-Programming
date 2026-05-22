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

    vector<int> result(n);
    result[0] = 1;
    set<int> done;
    ll left = 1;
    done.insert(1);
    for (ll i = 1; i < n; i++)
    {
        while (done.find(left) != done.end())
        {
            left++;
        }
        done.insert(left + result[i - 1

        done.insert(left);
        result[i] = left;
    }

    for (auto e : result)
    {
        cout << e << ' ';
    }
    cout << '\n';
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