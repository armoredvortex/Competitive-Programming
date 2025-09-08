#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;

    while (t--)
    {

        string s;
        cin >> s;
        char se = 'l';
        int l = 0, r = 0;
        int g1 = 0, g2 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'S')
            {
                if (se == 'l')
                {
                    l++;
                }
                else
                {
                    r++;
                }
            }
            else if (s[i] == 'R')
            {
                if (se == 'l')
                {
                    se = 'r';
                    r++;
                }
                else
                {
                    se = 'l';
                    l++;
                }
            }
            if (l - r >= 2 && l >= 5)
            {
                g1++;
                se = 'l';
                l = 0;
                r = 0;
            }
            else if (r - l >= 2 && r >= 5)
            {
                g2++;
                se = 'r';
                l = 0;
                r = 0;
            }
            else if (l == 10)
            {
                g1++;
                se = 'l';
                l = 0;
                r = 0;
            }
            else if (r == 10)
            {
                g2++;
                se = 'r';
                l = 0;
                r = 0;
            }
            if (s[i] == 'Q')
            {

                if (g1 >= 2)
                {
                    cout << g1 << " (winner) - " << g2 << "  " << endl;
                    continue;
                }
                else if (g2 >= 2)
                {
                    cout << g1 << " - " << g2 << " (winner) " << endl;
                    continue;
                }

                if (se == 'l')
                {
                    cout << g1 << " " << "(" << l << "*)" << " - " << g2 << " " << "(" << r << ")" << endl;
                }
                else
                {
                    cout << g1 << " " << "(" << l << ")" << " - " << g2 << " " << "(" << r << "*)" << endl;
                }
            }
        }
    }

    return 0;
}