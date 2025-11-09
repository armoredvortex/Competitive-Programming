#include <bits/stdc++.h>
using namespace std;
// #include "debugging.h"

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin >> n;
    vector<long long int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] < v[i])
        {
            flag = 0;
        }
    }

    if (flag)
    {
        cout << "1 1" << endl;
        return 0;
    }

    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            l = i;
            r = i + 1;
        }
    }

    // cerr << l << ' ' << r << "\n";
    for (int i = l; i > 0; i--)
    {
        if (v[i - 1] >= v[i])
        {
            l--;
            // cerr << v << endl;
            // cout << 'h' << "\n";
        }
        else
        {
            break;
        }
    }
    // cerr << l << ' ' << r << "\n";

    for (int i = r; i < n - 1; i++)
    {
        if (v[r] >= v[r + 1])
        {
            r++;
        }
        else
        {
            break;
        }
    }

    for (int i = l; i > 0; i--)
    {
        if (v[i - 1] > v[i])
        {
            cout << "impossible" << endl;
            return 0;
        }
    }

    for (int i = r; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            cout << "impossible" << endl;
            return 0;
        }
    }

    // check if l->r is decreasing
    int flagd = 1;
    for (int i = l; i < r; i++)
    {
        if (v[i + 1] > v[i])
        {
            flagd = 0;
        }
    }

    if (!flagd)
    {
        cout << "impossible" << endl;
        return 0;
    }

    if ((r == n - 1) || (v[l] <= v[r + 1]))
    {
        if ((l == 0) || (v[r] >= v[l - 1]))
        {
            cout << l + 1 << ' ' << r + 1 << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;
    return 0;
}