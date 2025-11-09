#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k = 100;
    int mk = 100;
    for (int i = 0; i < n; i++)
    {
        k += v[i];
        if (k > mk)
        {
            mk = k;
        }
    }

    cout << mk << "\n";
}