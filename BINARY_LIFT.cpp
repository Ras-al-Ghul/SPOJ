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

// <https://codeforces.com/contest/1142/problem/B>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2e5 + 5;
const int LG = log2(N) + 1;
 
int n, m, q;
int p[N], a[N], b[N], st[4 * N];
int nxt[LG][N];
 
void build(int node, int L, int R)
{
    if(L==R)
    {
        st[node] = b[L];
        return;
    }
    int M=(L+R)/2;
    build(node*2, L, M);
    build(node*2+1, M+1, R);
    st[node]=min(st[node*2], st[node*2+1]);
}
 
int query(int node, int L, int R, int i, int j)
{
    if(j<L || i>R)
        return 1e9;
    if(i<=L && R<=j)
        return st[node];
    int M=(L+R)/2;
    int left=query(node*2, L, M, i, j);
    int right=query(node*2 + 1, M+1, R, i, j);
    return min(left, right);
}
 
int walkAhead(int u, int h)
{
    // since you've stored 2nd, 4th, 8th, etc.
    // element, you jump accordingly, starting
    // from higher bits (longer jumps)
    for(int i=LG-1;i>=0;i--)
    {
        if((h>>i) & 1)
            u = nxt[i][u];
    }
    return u;
}
 
void precompute()
{
    for(int i=1;i<LG;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(nxt[i-1][j])
                nxt[i][j] = nxt[i-1][nxt[i-1][j]];
        }
    }
}
 
void work()
{
    map<int, int> reqd;
    for(int i = 1; i <= n - 1; i++)
        reqd[p[i]] = p[i + 1];
    reqd[p[n]] = p[1];
    map<int, int> idx;
    // store index of number which occurs
    // next in the sequence
    for(int i = m; i >= 1; i--)
    {
        if(idx.find(reqd[a[i]]) != idx.end())
            nxt[0][i] = idx[reqd[a[i]]];
        idx[a[i]] = i;
    }

    // compute to log(N) levels, where you store
    // next index of 2nd, 4th, 8th, 16th, element
    // of current sequence - the 2nd, 4th, etc.
    // are needed depending on length of sequence
    // n
    precompute();
    for(int i = 1; i <= m; i++)
    {
        // for each index i in the permutation,
        // find out using above binary lifting,
        // in log(N) time, where is index of 
        // last element if sequence begins at 
        // this index
        b[i] = walkAhead(i, n - 1);
        if(!b[i])
            b[i] = m + 1;
    }

    // build min segment tree
    build(1, 1, m);
    for(int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        // if end of sequence starting anywhere in
        // interval is less than right boundary,
        // there exists a sequence in this boundary
        int ans = query(1, 1, m, l, r) <= r;
        cout << ans;
    }
}
 
int main()
{
    IOS;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    work();
    return 0;
}