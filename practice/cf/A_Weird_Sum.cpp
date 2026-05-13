#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, vector<int>>> v(1e5 + 10);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int c;
            cin >> c;
            v[c].first.push_back(i);
            v[c].second.push_back(j);
        }
    }

    for (int i = 0; i < 1e5 + 10; i++)
    {
        sort(v[i].first.begin(), v[i].first.end());
        sort(v[i].second.begin(), v[i].second.end());
    }

    long long ans = 0;
    for (int i = 0; i < 1e5 + 10; i++)
    {
        for (int j = 0; j < v[i].first.size(); j++)
        {
            ans += (j - (v[i].first.size() - j - 1)) * v[i].first[j];
        }
        for (int j = 0; j < v[i].second.size(); j++)
        {
            ans += (j - (v[i].second.size() - j - 1)) * v[i].second[j];
        }
    }
    cout << ans;

    return 0;
}