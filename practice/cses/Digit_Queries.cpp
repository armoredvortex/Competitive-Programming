#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    vector<ll> p10(18, 1);
    for (int i = 1; i < 18; i++) {
        p10[i] = p10[i - 1] * 10;
    }

    vector<ll> v;
    v.push_back(0);
    for (ll i = 1; i <= 17; i++)
    {
        v.push_back(v.back() + i * 9 * p10[i - 1]);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;

        auto it = lower_bound(v.begin(), v.end(), k);
        ll n = it - v.begin();

        ll prev_digits = *(--it); 
        ll rem = k - prev_digits; 
        ll i = (rem - 1) / n;
        string num = to_string(p10[n - 1] + i);

        cout << num[(rem - 1) % n] << '\n';
    }
    
    return 0;
}