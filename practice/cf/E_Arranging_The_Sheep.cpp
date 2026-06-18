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
    string s;
    cin >> s;

    ll ct = count(s.begin(), s.end(), '*');
    ll a = 0, b = 0, c = 0, d = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            d += i;
        }
    }
    ll left = 0, right = 0;
    queue<ll> q1, q2;
    for (right = 0; right < ct; right++)
    {
        if (s[right] == '*')
        {
            d -= right;
        }
        else if (s[right] == '.')
        {
            c += right;
            q2.push(right);
        }
    }

    ll ans = d - c;
    while (right < n)
    {
        if (s[left] == '.' && s[right] == '.')
        {
            q2.push(right);
            c += right;
            if (q1.size())
            {
                b -= q1.front();
                q1.pop();
                b += q2.front();
                q1.push(q2.front());
                c -= q2.front();
                q2.pop();
            }
            else
            {
                c -= q2.front();
                q2.pop();
            }
        }
        else if (s[left] == '.' && s[right] == '*')
        {
            if (q1.size())
            {
                b -= q1.front();
                q1.pop();
                b += q2.front();
                q1.push(q2.front());
                c -= q2.front();
                q2.pop();
            }
            else
            {
                c -= q2.front();
                q2.pop();
            }
            d -= right;
        }
        else if (s[left] == '*' && s[right] == '.')
        {
            q2.push(right);
            c += right;
            q1.push(q2.front());
            b += q2.front();
            c -= q2.front();
            q2.pop();
            a += left;
        }
        else
        {
            d -= right;
            a += left;
            b += q2.front();
            c -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }

        left++;
        right++;
        ans = min(ans, d - c + b - a);
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