#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 2)
        {
            int x = 1;
            for (int i = 0; i < n; i++)
                cout << x + i << " ";
            cout << endl;
        }
        else
        {
            cout << 1 << " ";
            int x;
            for (x = n; x >= 2; x--)
                cout << x << " ";
            cout << endl;
        }
    }
}