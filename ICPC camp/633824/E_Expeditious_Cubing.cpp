#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<float> solves(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> solves[i];
    }

    sort(solves.begin(), solves.end());

    float target;
    cin >> target;

    float a = solves[1], b = solves[2], c = solves[3];

    float avg = (a + b + c) / 3;
    if (avg <= target)
    {
        cout << "infinite" << endl;
        return 0;
    }

    // cout << 3 * target - a - b << endl;
    // if (3 * target - a - b <= solves[0])
    // {
    //     cout << "impossible" << endl;
    //     return 0;
    // }
    if (solves[0] + a + b > 3 * target)
    {
        cout << "impossible" << endl;
        return 0;
    }

    cout << fixed << setprecision(2) << 3 * target - a - b << endl;
}