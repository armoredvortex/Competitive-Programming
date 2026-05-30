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

    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int left = j + 1, right = n - 1;
            while (left < right)
            {
                if (left == i || left == j)
                {
                    left++;
                }

                if (right == i || right == j)
                {
                    right--;
                }

                ll req = k - v[i].first - v[j].first;
                ll sum = v[left].first + v[right].first;
                if (sum == req)
                {
                    cout << v[i].second << ' ' << v[j].second << ' ' << v[left].second << ' ' << v[right].second;
                    return 0;
                }
                else if (sum > req)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}