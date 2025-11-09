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

    vector<ll> tees(n), a(n), b(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> tees[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    map<ll, multiset<ll>> m;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 1 & b[i] == 2 || a[i] == 2 && b[i] == 1)
        {
            m[12].insert(tees[i]);
        }
        else if (a[i] == 1 && b[i] == 3 || a[i] == 3 && b[i] == 1)
        {
            m[13].insert(tees[i]);
        }
        else if (a[i] == 2 && b[i] == 3 || a[i] == 3 && b[i] == 2)
        {
            m[23].insert(tees[i]);
        }
        else if (a[i] == 1 && b[i] == 1)
        {
            m[11].insert(tees[i]);
        }
        else if (a[i] == 2 && b[i] == 2)
        {
            m[22].insert(tees[i]);
        }
        else
        {
            m[33].insert(tees[i]);
        }
    }

    // for (auto e : m)
    // {
    //     cout << e.first << " : ";
    //     for (auto f : e.second)
    //     {
    //         cout << f << ' ';
    //     }
    //     cout << '\n';
    // }

    ll s;
    cin >> s;
    vector<ll> studs(s);
    for (ll i = 0; i < s; i++)
    {
        cin >> studs[i];
    }

    for (ll i = 0; i < s; i++)
    {
        if (studs[i] == 1)
        {
            ll e1 = LONG_LONG_MAX, e2 = LONG_LONG_MAX, e3 = LONG_LONG_MAX;
            if (m[12].size() != 0)
            {
                e1 = *m[12].begin();
            }
            if (m[13].size() != 0)
            {
                e2 = *m[13].begin();
            }
            if (m[11].size() != 0)
            {
                e3 = *m[11].begin();
            }

            if (e1 == LONG_LONG_MAX && e2 == LONG_LONG_MAX && e3 == LONG_LONG_MAX)
            {
                cout << -1 << ' ';
            }
            if (e1 < e2 && e1 < e3)
            {
                m[12].erase(m[12].begin());
                cout << e1 << ' ';
            }
            if (e2 < e3 && e2 < e1)
            {
                m[13].erase(m[13].begin());
                cout << e2 << ' ';
            }
            if (e3 < e2 && e3 < e1)
            {
                m[11].erase(m[11].begin());
                cout << e3 << ' ';
            }
        }
        else if (studs[i] == 2)
        {
            ll e1 = LONG_LONG_MAX, e2 = LONG_LONG_MAX, e3 = LONG_LONG_MAX;
            if (m[12].size() != 0)
            {
                e1 = *m[12].begin();
            }
            if (m[23].size() != 0)
            {
                e2 = *m[23].begin();
            }
            if (m[22].size() != 0)
            {
                e3 = *m[22].begin();
            }

            if (e1 == LONG_LONG_MAX && e2 == LONG_LONG_MAX && e3 == LONG_LONG_MAX)
            {
                cout << -1 << ' ';
            }
            if (e1 < e2 && e1 < e3)
            {
                m[12].erase(m[12].begin());
                cout << e1 << ' ';
            }
            if (e2 < e3 && e2 < e1)
            {
                m[23].erase(m[23].begin());
                cout << e2 << ' ';
            }
            if (e3 < e2 && e3 < e1)
            {
                m[22].erase(m[22].begin());
                cout << e3 << ' ';
            }
        }
        else
        {
            ll e1 = LONG_LONG_MAX, e2 = LONG_LONG_MAX, e3 = LONG_LONG_MAX;
            if (m[13].size() != 0)
            {
                e1 = *m[13].begin();
            }
            if (m[23].size() != 0)
            {
                e2 = *m[23].begin();
            }
            if (m[33].size() != 0)
            {
                e3 = *m[33].begin();
            }

            if (e1 == LONG_LONG_MAX && e2 == LONG_LONG_MAX && e3 == LONG_LONG_MAX)
            {
                cout << -1 << ' ';
            }
            if (e1 < e2 && e1 < e3)
            {
                m[13].erase(m[13].begin());
                cout << e1 << ' ';
            }
            if (e2 < e3 && e2 < e1)
            {
                m[23].erase(m[23].begin());
                cout << e2 << ' ';
            }
            if (e3 < e2 && e3 < e1)
            {
                m[33].erase(m[33].begin());
                cout << e3 << ' ';
            }
        }
    }
}