#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    set<int> crit2, crit3;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            crit2.insert(i + 1);
            i++;
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 2])
        {
            crit3.insert(i + 2);
            i += 2;
        }
    }

    set<int> crit;
    for (auto e : crit2)
    {
        crit.insert(e);
    }
    for (auto e : crit3)
    {
        crit.insert(e);
    }

    vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i];
        if (crit.find(i) != crit.end())
        {
            pre[i + 1]++;
        }
    }

    // cerr << crit << '\n'
    //      << pre << '\n';

    while (k--)
    {
        int l, r;
        cin >> l >> r;

        int total = pre[r] - pre[l];

        cout << total << '
    }
}