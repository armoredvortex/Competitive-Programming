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
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll d = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

    sort(v.rbegin(), v.rend());
    ll left = 0, right = n - 1;
    ll sum = 0;

    vll result;
    while (left <= right)
    {
        if (sum + v[left] < d)
        {
            sum += v[left];
            result.push_back(v[left]);
            left++;
        }
        else
        {
            sum += v[right];
            result.push_back(v[right]);
            right--;
        }
    }

    if (sum < d)
    {
        cout << "Yes\n";
        for (auto e : result)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "No\n";
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