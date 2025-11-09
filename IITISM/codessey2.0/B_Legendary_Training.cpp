#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(all(v));

    ll left = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (left >= n)
        {
            break;
        }
        if (v[left] >= i + 1)
        {
            ans++;
            left++;
        }
        else
        {
            while (left < n && v[left] < i + 1)
            {
                left++;
            }

            if (left < n)
            {
                if (v[left] >= i + 1)
                {
                    ans++;
                    left++;
                }
            }
        }
    }

    cout << ans << '\n';
}