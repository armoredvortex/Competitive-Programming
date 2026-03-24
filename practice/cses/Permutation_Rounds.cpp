#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long ll;
const int mod = 1000000007;

int prime[MAX];
unordered_map<int, int> max_map;

// Function to return a^n
int power(int a, int n)
{
    if (n == 0)
        return 1;
    int p = power(a, n / 2) % mod;
    p = (p * p) % mod;
    if (n & 1)
        p = (p * a) % mod;
    return p;
}

// Function to find the smallest prime factors
// of numbers upto MAX
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * 2; j < MAX; j += i)
            {
                if (prime[j] == 0)
                {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}

// Function to return the LCM modulo M
ll lcmModuloM(const int *ar, int n)
{

    for (int i = 0; i < n; i++)
    {
        int num = ar[i];
        unordered_map<int, int> temp;

        // Temp stores mapping of prime factor to
        // its power for the current element
        while (num > 1)
        {

            // Factor is the smallest prime factor of num
            int factor = prime[num];

            // Increase count of factor in temp
            temp[factor]++;

            // Reduce num by its prime factor
            num /= factor;
        }

        for (auto it : temp)
        {

            // Store the highest power of every prime
            // found till now in a new map max_map
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }

    ll ans = 1;

    for (auto it : max_map)
    {

        // LCM is product of primes to their highest powers modulo M
        ans = (ans * power(it.F, it.S)) % mod;
    }

    return ans;
}

ll MOD = 1e9 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    sieve();

    ll n;
    cin >> n;
    vll p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vll ord;
    vll visited(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        visited[i] = 1;

        ll ct = p[i] - 1;
        ll o = 1;
        while (ct != i)
        {
            visited[ct] = 1;

            o++;
            ct = p[ct] - 1;
        }
        ord.push_back(o);
    }

    int arr[ord.size()];
    for (int i = 0; i < ord.size(); i++)
    {
        arr[i] = ord[i];
    }
    cout << lcmModuloM(arr, ord.size());
}