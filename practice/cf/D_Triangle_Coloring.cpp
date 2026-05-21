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

const int MOD = 998244353;
vector<ll> fact;

ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % MOD, e /= 2)
        if (e & 1)
            ans = ans * b % MOD;
    return ans;
}

ll nCr(ll n)
{
    ll denom = modpow(fact[n / 2], 2);
    ll num = (fact[n] * modpow(denom, MOD - 2)) % MOD;

    return num;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    fact.resize(n + 1, 1);
    for (int i = 1; i < n + 1; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<vector<int>> v(n / 3, vector<int>(3, 0));
    for (int i = 0; i < n;)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i / 3][j];
            i++;
        }
    }

    ll ans = 1;
    for (auto e : v)
    {
        sort(e.begin(), e.end());
        if (e[0] < e[1])
        {
            ans *= 1;
        }
        else if (e[1] < e[2])
        {
            ans = (ans * 2) % MOD;
        }
        else
        {
            ans = (ans * 3) % MOD;
        }
    }

    ll triplets = n / 3;

    ll k = nCr(triplets);
    cout << (ans * k) % MOD;
}