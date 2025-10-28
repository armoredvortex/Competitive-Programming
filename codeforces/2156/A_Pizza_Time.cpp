#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve()
{
    ll n;

    cin >> n;
    // // cout << (n-2) / 2 << endl;
    // if(n%2 == 0){
    //     cout <<
    // }

    // cout << ceil(n / 3) << endl;

    ll ans = 0;
    while (n > 2)
    {
        if (n % 3 == 0)
        {
            ans += n / 3;
            n = n / 3;
        }
        else if (n % 3 == 2)
        {
            ans += (n - 2) / 3;
            n = (n - 2) / 3 + 2;
        }
        else
        {
            ans += (n - 1) / 3;
            n = (n - 1) / 3 + 1;
        }
    }

    cout << ans << endl;
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