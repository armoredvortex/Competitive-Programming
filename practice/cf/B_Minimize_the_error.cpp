#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(abs(a[i] - b[i]));
    }

    int k = k1 + k2;
    while (k)
    {
        auto e = pq.top();
        pq.pop();

        if (e == 0)
        {
            break;
        }

        pq.push(--e);
        k--;
    }

    long long ans = 0;
    while (!pq.empty())
 e = pq.top();
        pq.pop();
        ans += e * e;
    }

    if (k % 2)
    {
        ans++;
    }

    cout << ans;
}