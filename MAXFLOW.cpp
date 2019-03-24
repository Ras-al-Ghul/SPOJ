#define _USE_MATH_DEFINES
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

// const int halfN = 5e3+2, N = 2*5e3 + 5, INF = 1e9;

// MAXFLOW which works well when edges are only added
// and not removed - can be used to find maximum matching

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

vector<edge> G[N];
vector<bool> used(N,0);

void add_edge(int from, int to, int cap){
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;

    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int f = 0;
    for(;;){
        fill(all(used), false);
        int d = dfs(s, t, INF);
        if(d == 0) return f;
        f += d;
    }
}

int n, m, d;
// source: 0
// sink: N-1
int ss = 0, tt = N-1;

int main(){
	bolt;
	cin >> n >> m;
	
	vector<int> potential(n+1);
	vector<int> club(n+1);
	
	forr(i,1,n+1)
		cin >> potential[i];
	forr(i,1,n+1)
		cin >> club[i];

	vector<bool> present(n+1,1);

	cin >> d;
	vector<int> days(d);
	forr(i,0,d){
		cin >> days[i];
		present[days[i]] = false;
	}

	forr(i,1,m+1)
		add_edge(ss, i, 1);

	forr(i,1,n+1)
		if(present[i])
			add_edge(club[i], halfN+potential[i], 1);

	vector<int> ans(d);

	int cur_mex = -1;
	int cur_flow = 0;
	for(int i = d-1; i >= 0; --i){
		while(/*cur_flow < halfN and*/ cur_flow == cur_mex + 1){
			cur_mex++;
			add_edge(halfN+cur_mex, tt, 1);
			cur_flow += max_flow(ss, tt);
		}
		
		ans[i] = cur_mex;

		add_edge(club[days[i]], halfN+potential[days[i]], 1);
		cur_flow += max_flow(ss, tt);
	}

	for(auto &a : ans)
		cout << a << endl;

	return 0;
}