#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.1415926535897932
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define forr(i,p,n) for(int i=p;i<n;i++)
#define sz(x) ((int)(x).size())
#define _USE_MATH_DEFINES
typedef long long ll;
typedef unsigned long long ull;

ll mult(ll a,ll b, ll p=MOD){ll ans = a; ans *= b; return ((ans >= p) ? ans % p : ans);}
ll add(ll a, ll b, ll p=MOD){ll ans = a + b; return ((ans >= p) ? ans - p : ans);}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}

// ncr mod p
// vector<ll> fact(200005,0);
// vector<ll> invvec(200005,0);

// void fillfact(){
//     fact[0] = 1; invvec[0] = 1;
//     fact[1] = 1; invvec[1] = 1;
//     forr(i,2,200001){
//         fact[i] = mult(fact[i-1],i);
//         invvec[i] = inv(fact[i]);
//     }
// }

// ll ncr(ll n, ll r){
//     return (mult(fact[n],mult(invvec[r],invvec[n-r])));
// }

// disjoint sets union
// vector<ll> par(200005,0);
// vector<ll> rnk(200005,0);
// ll find_root(ll v) {
//     return par[v] == v ? v : (par[v] = find_root(par[v]));
// }
 
// void merge(ll x,ll y) {
//     if ((x = find_root(x)) == (y = find_root(y))) return;
//     if(rnk[y] > rnk[x])
//         swap(x, y);
//     par[y] = x;
//     rnk[x] += rnk[y];
// }


// sieve for first 1000 primes
// vector<bool> prime(100005,0);
// vector<int> vec;

// void sieve() {
//     forr(i, 2, 8005) {
//         if (!prime[i]) {
//             vec.pb(i);
//             for(int j = 2 * i; j < prime.size(); j += i) 
//                 prime[j] = 1;
//         }
//     }
// }

// string s, t;
// int zs, ze, os, oe, ns, nt, nz = 0, no = 0;
// string z = "", o = "";
// int ans = 0;

// int recurse(int ind, int tind){
//     // cout << z << " " << o << " " << ind << " " << tind << endl;
//     if(tind == nt and ind == ns)
//         return 1;
//     if(ind == ns)
//         return 0;
//     if(s[ind] == '0'){
//         if(z != ""){
//             int a = t.find(z, tind);
//             if(a == tind){
//                 return recurse(ind+1, tind+sz(z));
//             }
//             else
//                 return 0;
//         }
//         else{
//             int temp = 0;
//             forr(i,zs,ze+1){
//                 if(tind + (i-zs) >= nt)
//                     return temp;
//                 z = t.substr(tind,i-zs+1);
//                 if(z == o){
//                     z = ""; continue;
//                 }
//                 if(zs < os){
//                     ans += recurse(ind+1, tind+sz(z));
//                     // cout << z << " z " << ans << endl;
//                 }
//                 else{
//                     temp += recurse(ind+1, tind+sz(z));
//                 }
//                 z = "";
//             }
//             return temp;
//         }
//     }
//     else if(s[ind] == '1'){
//         if(o != ""){
//             int a = t.find(o, tind);
//             if(a == tind){
//                 return recurse(ind+1, tind+sz(o));
//             }
//             else
//                 return 0;
//         }
//         else{
//             int temp = 0;
//             forr(i,os,oe+1){
//                 if(tind + (i-os) >= nt)
//                     return temp;
//                 o = t.substr(tind,i-os+1);
//                 if(o == z){
//                     o = ""; continue;
//                 }
//                 if(os < zs){
//                     ans += recurse(ind+1, tind+sz(o));
//                 }
//                 else{
//                     temp += recurse(ind+1, tind+sz(o));
//                     // cout << o << " o " << temp << endl;
//                 }
//                 o = "";
//             }
//             return temp;
//         }
//     }
//     else{
//         return 0;
//     }
// }

// int main(){
//     bolt;
//     cin >> s >> t;
//     ns = sz(s); nt = sz(t);
    
//     zs = s.find('0');
//     os = s.find('1');

//     forr(i,0,ns)
//         s[i] == '0' ? nz++ : no++;

//     ze = nt - (ns - zs);
//     oe = nt - (ns - os);
//     // cout << zs << " " << ze << endl;
//     // cout << os << " " << oe << endl;

//     recurse(0,0);

//     cout << ans << endl;
//     return 0;
// }

// Problem 1056 E
// <https://threads-iiith.quora.com/String-Hashing-for-competitive-programming>
// <https://codeforces.com/blog/entry/12145>

ll P = 31;
ll invv = inv(P);

void build_prefix_hash(string &a, vector<ll> &prefix_hash){
    ll l = sz(prefix_hash);
    prefix_hash[0] = 0;
    ll p = 1;
    forr(i,0,l-1){
        prefix_hash[i+1] = prefix_hash[i] + 
                           ((a[i] - ('a'-1)) * p);
        p = (p*P) % MOD;
    }
}


// inclusive index i,j
ll calchash(ll i, ll j, vector<ll> &prefix_hash){
    ll hash = (prefix_hash[j+1] - prefix_hash[i]) % MOD;
    hash = (hash * fpow(invv, i)) % MOD;
    return (hash + MOD) % MOD;
}

int main(){
    bolt;
    string bin, alpha;
    cin >> bin >> alpha;
    ll n = sz(alpha), l = sz(bin);

    // stringlen + 1
    vector<ll> prefix_hash(n+1);
    build_prefix_hash(alpha, prefix_hash);

    ll count[2] = {0,0};
    for(const auto &c : bin)
        count[c-'0']++;

    ll ans = 0;
    forr(z, 1, n){
        if(count[0] * z >= n)
            break;
        if((n - count[0]*z) % count[1]) continue;
        int o = (n - count[0]*z) / count[1];
        ll init_hash[2] = {-1,-1};
        ll len[2] = {z,o};
        ll low = 0;
        bool flag = true;
        for(const auto &c : bin){
            int idx = c - '0';
            if(init_hash[idx] == -1){
                init_hash[idx] = calchash(low, 
                                          low+len[idx]-1,
                                          prefix_hash);
                low += len[idx];
                continue;
            }
            ll hash = calchash(low,
                                low+len[idx]-1,
                                prefix_hash);
            if(hash != init_hash[idx]){
                flag = false;
                break;
            }
            low = low + len[idx];
        }
        // both 0 and 1 should not be same string as well
        if(flag and init_hash[0] != init_hash[1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}