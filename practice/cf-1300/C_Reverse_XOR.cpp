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

void solve()
{
    ll k;
    cin >> k;

    vector<int> v;
    while (k)
    {
        v.push_back(k & 1ll);
        k /= 2;
    }

    ll left = 0;
    while (left < v.size() && v[left] != 1)
    {
        left++;
    }
    ll n = v.size() - left;
    if (n % 2 == 0)
    {
        int r = n - 1;
        for (int i = 0; i < n / 2; i++)
        {
            if (v[left + i] != v[left + r])
            {
                cout << "NO\n";
                return;
            }
            r--;
        }

        cout << "YES\n";
    }
    else
    {
        if (v[left + n / 2] == 1)
        {
            cout << "NO\n";
            return;
        }

        // cerr << n;
        int r = n - 1;
        // cerr << v << '\n';
        // cerr << left << ' ' << r - 1 << '\n';
        // cerr << v[left] << ' ' << v[left + r - 1] << '\n';
        for (int i = 0; i < n / 2; i++)
        {
            // cerr << v[left + i] << ' ' << v[left + r - 1] << '\n';
            if (v[left + i] != v[left + r])
            {
                cout << "NO\n";
                return;
            }
            r--;
        }

        cout << "YES\n";
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