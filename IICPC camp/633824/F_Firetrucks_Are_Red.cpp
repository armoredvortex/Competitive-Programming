#include <bits/stdc++.h>

using namespace std;
#define int long long int
struct edge
{
    int u;
    int v;
    int w;
};
vector<int> parent;
vector<int> size_;
class dsu
{
public:
    int n;

    dsu(int x)
    {
        init(x);
    }
    void init(int x)
    {
        n = x;
        parent.resize(n + 1);
        size_.resize(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int find(int i)
    {
        int a = i;
        if (parent[i] != i)
        {
            a = find(parent[i]);
        }
        parent[i] = a;
        return a;
    }
    bool union_(int a, int b)
    {
        int a_ = find(a);
        int b_ = find(b);
        if (find(a) != find(b))
        {
            if (size_[a_] < size_[b_])
            {
                swap(a_, b_);
            }
            parent[b_] = a_;
            size_[a_] += size_[b_];
            return true;
        }
        return false;
    }
};

#define int long long int

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;

    while (t--)
    {
        int n;
        cin >> n;
        map<int, vector<int>> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (int j = 0; j < x; j++)
            {
                int c;
                cin >> c;
                a[c].push_back(i);
            }
        }
        // for(auto i:a)
        // {
        //     cout<<i.first<<" - ";
        //     for(int j = 0; j<i.second.size(); j++)
        //          cout<<i.second[j]<<" ";
        //     cout<<endl;
        // }
        dsu DSU(n);
        vector<edge> mst;

        for (auto i : a)
        {
            for (int j = 1; j < i.second.size(); j++)
            {
                if (DSU.union_(i.second[0], i.second[j]) == true)
                {
                    mst.push_back({i.second[0], i.second[j], i.first});
                }
            }
        }
        if (mst.size() == n - 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << mst[i].u + 1 << " " << mst[i].v + 1 << " " << mst[i].w << endl;
            }
        }
        else
        {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
 