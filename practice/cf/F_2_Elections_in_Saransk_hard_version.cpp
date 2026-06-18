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

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M)
{
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod)
{
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1)
            ans = modmul(ans, b, mod);
    return ans;
}

const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes()
{
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vi pr = {2}, sieve(S + 1);
    pr.reserve(int(LIM / log(LIM) * 1.1));
    vector<pii> cp;
    for (int i = 3; i <= S; i += 2)
        if (!sieve[i])
        {
            cp.push_back({i, i * i / 2});
            for (int j = i * i; j <= S; j += 2 * i)
                sieve[j] = 1;
        }
    for (int L = 1; L <= R; L += S)
    {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i = idx; i < S + L; idx = (i += p))
                block[i - L] = 1;
        rep(i, 0, min(S, R - L)) if (!block[i]) pr.push_back((L + i) * 2 + 1);
    }
    for (int i : pr)
        isPrime[i] = 1;
    return pr;
}

const int mod = 1e9 + 7;

int main()
{
    eratosthenes();
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vll primes;
    for (ll i = 2; i < 5 * 1e5 + 10; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vll v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<ll, ll> xfact;
        for (ll j = 0; j < primes.size() && primes[j] <= sqrt(x); j++)
        {
            while (x % primes[j] == 0)
            {
                x /= primes[j];
                xfact[primes[j]]++;
            }
        }

        // vll mp(primes.back() + 10, 0);
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < primes.size() && primes[j] <= sqrt(v[i]); j++)
            {
                while (v[i] % primes[j] == 0)
                {
                    v[i] /= primes[j];
                    mp[primes[j]]++;
                }
            }
            if (v[i] != 1)
            {
                mp[v[i]]++;
            }
        }
        // cerr << mp << '\n';

        ll ans = 1;
        for (auto e : mp)
        {
            if (xfact.find(e.first) == xfact.end())
            {
                ans = (ans * (e.second + 1));
            }
        }
        cout << ans << '\n';
    }
}
