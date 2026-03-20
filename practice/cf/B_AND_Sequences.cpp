#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

// #include <debugging.h>

const ll mod = 1000000007;

vll fact(200009);

void pre()
{
    fact[0] = 1;

    for (ll i = 1; i < 200009; i++)
    {
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    }
}

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll k = 60;
    vector<vector<ll>> bits(n, vector<ll>(k));
    for (ll i = 0; i < n; i++)
    {
        auto e = v[i];
        for (ll j = 0; j < k; j++)
        {
            bits[i][j] = e % 2;
            e /= 2;
        }
    }

    vector<ll> full(k, 0);

    for (ll i = 0; i < k; i++)
    {
        ll flag = 1;
        for (ll j = 0; j < n; j++)
        {
            if (bits[j][i] == 0)
            {
                flag = 0;
            }
        }
        if (flag)
        {
            full[i] = 1;
        }
    }

    ll kkk = 0;
    for (ll i = 0; i < n; i++)
    {
        ll flag = 1;
        for (ll j = 0; j < k; j++)
        {
            if (!full[j] && bits[i][j])
            {
                flag = 0;
            }
        }
        if (flag)
        {
            kkk++;
        }
    }

    if (kkk < 2)
    {
        cout << 0 << '\n';
        return;
    }
    ll ans = kkk % mod;
    ans = ans * ((kkk - 1) % mod) % mod;
    ans = (ans * fact[n - 2]) % mod;
    cout << ans << '\n';
    // cerr << bits << endl;
    // cerr << full << endl;
    // cerr << kkk;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    pre();
    int t;
    cin >> t;
    while (t--)
        solve();
}