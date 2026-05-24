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

const ll mod = 1000000007;
ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1)
            ans = ans * b % mod;
    return ans;
}

ll modinv(ll a)
{
    return modpow(a, mod - 2);
}

ll modmul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}
ll frac(ll a, ll b)
{
    return modmul(a, modinv(b));
}

vector<vector<ll>> multiplymatrix(vector<vector<ll>> A, vector<vector<ll>> B)
{
    vector<vector<ll>> C(2, vector<ll>(2, 0));
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                C[i][j] = (C[i][j] + modmul(A[i][k], B[k][j])) % mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> modpowmatrix(vector<vector<ll>> b, ll e)
{
    vector<vector<ll>> ans = {{1, 0}, {0, 1}};
    while (e > 0)
    {
        if (e & 1)
        {
            ans = multiplymatrix(ans, b);
        }
        b = multiplymatrix(b, b);
        e /= 2;
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll a, b, n;
    cin >> a >> b >> n;

    ll P_h = frac(a, b);
    ll P_t = frac(b - a, b);

    vector<vector<ll>> M = {
        {0, P_h},
        {P_t, P_t}};

    if (n == 1)
    {
        cout << (P_h + P_t) % mod;
        return 0;
    }
    vector<vector<ll>> res = modpowmatrix(M, n - 1);

    ll final_h = (modmul(res[0][0], P_h) + modmul(res[0][1], P_t)) % mod;
    ll final_t = (modmul(res[1][0], P_h) + modmul(res[1][1], P_t)) % mod;

    cout << (final_h + final_t) % mod;
    return 0;
}