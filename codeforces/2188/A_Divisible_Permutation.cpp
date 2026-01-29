#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

void solve() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    ll ct = 1;
    ll cx = n;
    for(int i=n-1; i>=0; i-=2){
        v[i] = ct;
        ct++;
    }
    for(int i=n-2; i>=0; i-=2){
        v[i] = cx;
        cx--;
    }

    for(auto e: v){
        cout << e << ' ';
    }
    cout << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int t; cin >> t;
    while (t--) solve();
}