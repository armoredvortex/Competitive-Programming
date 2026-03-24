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

#define MAX 1e6

vll occ(1e6 + 10, 0);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        occ[a]++;
    }

    for (ll i = MAX; i > 0; i--)
    {
        ll ct = 0;
        for (ll j = 0; j * i <= MAX; j++)
        {
            ct += occ[j * i];
        }
        if (ct >= 2)
        {
            cout << i;
            break;
        }
    }
}