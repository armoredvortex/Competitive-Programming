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

    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(all(v));
    ll left = 0, right = 0;
    while (left < right)
    {
        ll k = min(v[left], v[right]);
        v[left] -= k;
        v[right] -= k;
        if (!v[left])
        {
            left++;
        }
        if (!v[right])
        {
            right--;
        }
    }
    if (left == right)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}