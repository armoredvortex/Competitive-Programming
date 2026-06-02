#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, x, s;
    cin >> n >> x >> s;

    string str;
    cin >> str;

    ll empty = x, nonempty = 0;
    ll ahold = 0;
    ll ans = 0;

    auto resolve = [&]()
    {
        while (ahold > nonempty && empty > 0)
        {
            ahold--;
            empty--;
            nonempty += s - 1;
            ans++;
        }

        if (ahold > nonempty && empty == 0)
        {
            ahold = nonempty;
        }
    };

    for (ll i = 0; i < n; i++)
    {
        if (str[i] == 'A')
        {
            ahold++;
        }
        else if (str[i] == 'I')
        {
            if (empty)
            {
                ans++;
                empty--;
                nonempty += s - 1;
            }
        }
        else if (str[i] == 'E' && s > 1)
        {
            if (nonempty)
            {
                ans++;
                nonempty--;
            }
        }

        resolve();
    }

    if (ahold)
    {
        ans += ahold;
    }

    cout << ans << '\n';
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