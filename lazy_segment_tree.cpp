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

// <https://codeforces.com/contest/1108/problem/E2>
// neat implementation of segment tree with 
// range queries and range updates.
// solution required using sweepline technique.
// for all indices i, 
// 	apply ops which begin at i;
// 	do the calc;
// 	apply ops which end at i;
	
const int N = 1e5 + 5;
int n, m, ans = 0, ansind = -1;
vector<int> a(N);
vector<int> stmin(4*N), stmax(4*N), lazymin(4*N), lazymax(4*N);
vector<pair<int,int> > segs(N);
vector<vector<int> > strt(N);
vector<vector<int> > ed(N);

void build(int node, int L, int R){
	if(L == R){
		stmin[node] = a[L];
		stmax[node] = a[L];
		return;
	}
	int M = (L+R) / 2;
	build(node*2, L, M);
	build(node*2 + 1, M+1, R);
	stmin[node] = min(stmin[node*2], stmin[node*2+1]);
	stmax[node] = max(stmax[node*2], stmax[node*2+1]);
}
/////////////////////////////////////////////////////////
void propagatemin(int node, int L, int R){
	if(L != R){
		lazymin[node*2] += lazymin[node];   
		lazymin[node*2+1] += lazymin[node];
	}
	stmin[node] += lazymin[node];
	lazymin[node] = 0;
}

int querymin(int node, int L, int R, int i, int j){
	if(lazymin[node])
		propagatemin(node, L, R);
	if(j < L or i > R)
		return 1e9;
	if(i <= L and j >= R)
		return stmin[node];
	int M = (L+R) / 2;
	int left = querymin(node*2, L, M, i, j);
	int right = querymin(node*2+1, M+1, R, i, j);
	return min(left, right);
}

void updatemin(int node, int L, int R, int i, int j, int val){
	if(lazymin[node])
		propagatemin(node, L, R);
	if(j < L or i > R)
		return;
	if(i <= L and j >= R){
		lazymin[node] += val;
		propagatemin(node, L, R);
		return;
	}
	int M = (L+R) / 2;
	updatemin(node*2, L, M, i, j, val);
	updatemin(node*2+1, M+1, R, i, j, val);
	stmin[node] = min(stmin[node*2], stmin[node*2+1]);
}
/////////////////////////////////////////////////////////
void propagatemax(int node, int L, int R){
	if(L != R){
		lazymax[node*2] += lazymax[node];   
		lazymax[node*2+1] += lazymax[node];
	}
	stmax[node] += lazymax[node];
	lazymax[node] = 0;
}

int querymax(int node, int L, int R, int i, int j){
	if(lazymax[node])
		propagatemax(node, L, R);
	if(j < L or i > R)
		return -1e9;
	if(i <= L and j >= R)
		return stmax[node];
	int M = (L+R) / 2;
	int left = querymax(node*2, L, M, i, j);
	int right = querymax(node*2+1, M+1, R, i, j);
	return max(left, right);
}

void updatemax(int node, int L, int R, int i, int j, int val){
	if(lazymax[node])
		propagatemax(node, L, R);
	if(j < L or i > R)
		return;
	if(i <= L and j >= R){
		lazymax[node] += val;
		propagatemax(node, L, R);
		return;
	}
	int M = (L+R) / 2;
	updatemax(node*2, L, M, i, j, val);
	updatemax(node*2+1, M+1, R, i, j, val);
	stmax[node] = max(stmax[node*2], stmax[node*2+1]);
}
/////////////////////////////////////////////////////////
int main(){
	bolt;
	cin >> n >> m;
	
	forr(i,1,n+1)
		cin >> a[i];
	
	build(1, 1, n);
	
	forr(i,1,m+1){
		cin >> segs[i].first >> segs[i].second;
		updatemin(1, 1, n, segs[i].first, segs[i].second, -1);
		updatemax(1, 1, n, segs[i].first, segs[i].second, -1);
		strt[segs[i].first].pb(i);
		ed[segs[i].second].pb(i);
	}

	forr(i,1,n+1){
		for(auto &j : strt[i]){
			updatemin(1, 1, n, segs[j].first, segs[j].second, 1);
			updatemax(1, 1, n, segs[j].first, segs[j].second, 1);
		}
		int tempmin = querymin(1, 1, n, 1, n);
		int tempmax = querymax(1, 1, n, 1, n);
		if(tempmax - tempmin > ans){
			ans = tempmax - tempmin;
			ansind = i;
		}
		for(auto &j : ed[i]){
			updatemin(1, 1, n, segs[j].first, segs[j].second, -1);
			updatemax(1, 1, n, segs[j].first, segs[j].second, -1);
		}
	}

	cout << ans << endl;
	
	vector<int> indices;
	forr(i,1,m+1){
		if(!(segs[i].first <= ansind and ansind <= segs[i].second))
			indices.pb(i);
	}
	cout << sz(indices) << endl;
	for(auto &i : indices)
		cout << i << " ";
	cout << endl;
	return 0;
}