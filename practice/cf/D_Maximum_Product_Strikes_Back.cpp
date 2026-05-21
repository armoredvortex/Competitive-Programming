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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = v[0];
    ll ansl = 0, ansr = 0;
    pair<ll, ll> mn = {v[0], 0}, mx = {v[0], 0};
    for (ll i = 1; i < n; i++)
    {
        if (v[i] < 0)
        {
            pair<ll, ll> oldmn = mn;
            mn.first = mx.first * v[i];
            if(n)
        }
        else if (v[i] == 0)
        {
            mn = {1, i};
            mx = {1, i};
        }
        else
        {
            mn.first *= v[i];
            mx.first *= v[i];
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