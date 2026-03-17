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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll q;
    cin >> q;
    while (q--)
    {
        ll m;
        char c;
        cin >> m >> c;

        ll left = 0, right = 0;
        ll ans = 0;
        ll non_c = 0;
        while (right < n)
        {
            if (s[right] != c)
            {
                non_c++;
            }
            while (non_c > m)
            {
                if (s[left] != c)
                {
                    non_c--;
                }
                left++;
            }
            ans = max(right - left + 1, ans);
            right++;
        }
        cout << ans << '\n';
    }
}