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

const int LIM = 1e6;
bitset<LIM> isPrime;
vector<ll> primes;

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

void solve()
{
    ll n;
    cin >> n;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        cout << primes[idx] * primes[idx + 1] << ' ';
        idx++;
    }
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    eratosthenes();

    for (int i = 2; i < 200000; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    // cout << primes.size();
    int t;
    cin >> t;
    while (t--)
        solve();
}