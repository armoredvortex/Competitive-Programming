#include <bits/stdc++.h>
// #include "debugging.h"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    int p;
    cin >> p;
    set<int> pegs;
    for (int i = 0; i < p; i++)
    {
        int pi;
        cin >> pi;
        pegs.insert(pi);
    }

    map<int, int> peg_count;
    for (int i = 0; i < n; i++)
    {
        auto canv = v[i];
        int size = 0;
        auto l = pegs.lower_bound(canv.first);
        auto r = pegs.upper_bound(canv.second);
        size = distance(l, r);
        peg_count[i] = size;
    }

    // cerr << peg_count << "\n";

    vector<int> new_pegs;
    for (int i = 0; i < n; i++)
    {
        auto e = v[i];
        int size = peg_count[i];
        if (size > 2)
        {
            cout << "impossible" << "\n";
            return 0;
        }
        if (size == 2)
        {
            continue;
        }
        else if (size == 0)
        {
            new_pegs.push_back(e.first + 1);
            if ((i == n - 1) || (peg_count[i + 1] < 2))
            {
                new_pegs.push_back(e.second);
                if ((i != n - 1) && (v[i].second == v[i + 1].first))
                {
                    peg_count[i + 1]++;
                }
            }
            else
            {
                new_pegs.push_back(e.second - 1);
            }
        }
        else
        {
            if (pegs.find(e.second) != pegs.end())
            {
                new_pegs.push_back(e.second - 1);
            }
            else
            {
                if ((i == n - 1) || peg_count[i + 1] < 2)
                {
                    new_pegs.push_back(e.second);
                    if ((i != n - 1) && (v[i].second == v[i + 1].first))
                    {
                        peg_count[i + 1]++;
                    }
                }
                else
                {
                    // int a = *pegs.lower_bound(e.first);
                    for (int i = e.first + 1; i < e.second - 1; i++)
                    {
                        if (pegs.find(i) == pegs.end())
                        {
                            new_pegs.push_back(i);
                            break;
                        }
                    }

                    // new_pegs.push_back(*pegs.lower_bound(e.first) + 1);
                }
            }
        }
    }
    // cerr << new_pegs << "\n";
    cout << new_pegs.size() << endl;
    for (auto &e : new_pegs)
    {
        cout << e << ' ';
    }
    cout << "\n";
}