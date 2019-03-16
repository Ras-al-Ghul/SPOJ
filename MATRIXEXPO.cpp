// f(n) = f(n-1) + f(n-m)
// is the recurrence relation

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

ll mult(ll a,ll b, ll p=MOD){ll ans = ((a%p)*(b%p))%p; return (ans+p)%p;}
ll add(ll a, ll b, ll p=MOD){ll ans = (a%p + b%p)%p; return (ans+p)%p;}
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
// vector<ll> par(150005,0);
// vector<ll> rnk(150005,0);
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

const int N=1e5+5;
const int SZ=105;

struct matrix
{
    ll arr[SZ][SZ];

    void reset()
    {
        memset(arr, 0, sizeof(arr));
    }

    void makeiden()
    {
        reset();
        for(ll i=0;i<SZ;i++)
        {
            arr[i][i] = 1;
        }
    }

    matrix operator + (const matrix &o) const 
    {
        matrix res;
        for(ll i=0;i<SZ;i++)
        {
            for(ll j=0;j<SZ;j++)
            {
                res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
            }
        }
        return res;
    }

    matrix operator * (const matrix &o) const 
    {
        matrix res;
        for(ll i=0;i<SZ;i++)
        {
            for(ll j=0;j<SZ;j++)
            {
                res.arr[i][j] = 0;
                for(ll k=0;k<SZ;k++)
                {
                    res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, ll b)
{
    matrix res;
    res.makeiden();
    while(b)
    {
        if(b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll n, m;
ll res[SZ], res2[SZ];

int main(){
    bolt;
    cin>>n>>m;
    matrix ans;
    ans.makeiden();
    for(ll i=0;i<m;i++)
        res[i]=1;
    if(n<m)
    {
        cout<<res[n];
        return 0;
    }
    matrix mat;
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(i==0)
            {
                if(j-i==0 || j-i==m-1)
                    mat.arr[i][j]=1;
            }
            else
            {
                if(i==j+1)
                    mat.arr[i][j]=1;
            }
        }
    }
    matrix expo=power(mat, n-m+1);
    ans = ans * expo;
    for(ll i=0;i<m;i++)
    {
        res2[i]=0;
        for(ll j=0;j<m;j++)
            res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
    }
    for(ll i=0;i<SZ;i++)
        res[i]=res2[i];
    cout<<res[0]<<endl;
    return 0;
}