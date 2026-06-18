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
    ll n, m;
    cin >> n >> m;
    ll ncpy = n;
    ll two = 0, five = 0;
    while (n % 2 == 0)
    {
        two++;
        n /= 2;
    }
    while (n % 5 == 0)
    {
        five++;
        n /= 5;
    }

    ll k = 1;
    while (true)
    {
        if (two - five > 0)
        {
            if (5 * k > m)
            {
                break;
            }
            else
            {
                k *= 5;
                five++;
            }
        }
        else if (five - two > 0)
        {
            if (2 * k > m)
            {
                break;
            }
            else
            {
                k *= 2;
                two++;
            }
        }
        else
        {
            if (10 * k > m)
            {
                break;
            }
            else
            {
                k *= 10;
            }
        }
    }
    // cerr << k << '\n';
    if (k == 1)
    {
        cout << ncpy * m << '\n';
    }
    else
    {
        cout << (m / k) * k * ncpy << '\n';
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