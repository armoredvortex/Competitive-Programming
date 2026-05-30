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

    ll n, k;
    cin >> n >> k;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll mn = accumulate(v.begin(), v.begin() + k, 0ll);
    ll sum = mn;
    ll mni = 1;
    for (ll i = 0; i + k < n; i++)
    {
        sum += v[i + k];
        sum -= v[i];

        if (sum < mn)
        {
            mn = sum;
            mni = i + 2;
        }
    }
    cout << mni;
}