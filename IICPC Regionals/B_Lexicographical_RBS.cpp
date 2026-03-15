#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<ll,ll>> ct(k);
    ll c1 = k/2;
    ll c2 = k/2;

    for (ll i = 0; i < k; i++)
    {
        if(s[i] == '('){
            c1--;
        } else {
            c2--;
        }
        ct[i] = {c1, c2};
    }

    string result;
    ll excess = n - k;#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<ll,ll>> ct(k);
    ll c1 = k/2;
    ll c2 = k/2;

    for (ll i = 0; i < k; i++)
    {
        if(s[i] == '('){
            c1--;
        } else {
            c2--;
        }
        ct[i] = {c1, c2};
    }

    string result;
    ll excess = n - k;
    for(ll i=0; i<k; i++){
        if(ct[i].first == 0){
            while(excess){
                result += '(';
                excess--;
            }
        }
        result += s[i];
    }

    cout << result << '\n';
    
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}
    for(ll i=0; i<k; i++){
        if(ct[i].first == 0){
            while(excess){
                result += '(';
                excess--;
            }
        }
        result += s[i];
    }

    cout << result << '\n';
    
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}