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

    ll k = (1 << n) - 1;

    set<ll> s;

    cout << k << ' ';
    s.insert(k);
    k >>= 1;
    cout << k << ' ';
    s.insert(k);
    k >>= 1;
    while (k)
    {
        auto j = n - (64 - __countl_zero((unsigned long long)k)) - 1;

        auto h = 1 << ((64 - __countl_zero((unsigned long long)k)) + 1);

        auto lmno = k;
        for (ll i = 0; i < (1 << j); i++)
        {
            if (s.find(lmno) == s.end())
            {
                cout << lmno << ' ';
                s.insert(lmno);
            }
            lmno += h;
        }

        // cout << k << ' ';
        // s.insert(k);
        k >>= 1;
    }

    for (ll i = 0; i < (1 << n) - 1; i++)
    {
        if (s.find(i) == s.end())
        {
            cout << i << ' ';
        }
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

// 15 7 3 11 1 5 9 13 0

// 1111 0111 0011 1011 0001 0101 1001 1101 0000
// 4 3 2 2 1 1 1 1

// 0011 1000

// 111 011 001 101 000 010