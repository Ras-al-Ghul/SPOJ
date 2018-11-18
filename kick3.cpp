
// To celebrate the anniversary of Googleland, N couples are going to go for a boat ride in a rowboat. The rowboat is very long, but it is only one person wide, so the people will sit in a line from front to back.

// However, during a rehearsal of the voyage, the boat did not move! After investigating, the organizers found that some newlywed couples were not rowing, but writing love poems for each other the whole time. Specifically, there are M pairs of newlywed couples. If the two members of a newlywed couple are sitting next to each other, they will be so busy writing poems that they will not row.

// Now the organizers have come to you, the smartest person in Googleland, to ask, how many possible ways are there to arrange all 2N people on the rowboat, such that for each of the M newlywed couples, the two members are not sitting next to each other? Two ways are different if there is some position in the boat at which the two ways use different people. Notice that for the purpose of counting the number of ways, the two members of a couple are not considered to be interchangeable. Since the number can be very large, the organizers only want to know the value of the answer modulo 1000000007(109+7).

// Input 
 	
// Output 
 
// 5
// 2 1
// 2 2
// 3 1
// 3 2
// 10 5

// Case #1: 12
// Case #2: 8
// Case #3: 480
// Case #4: 336
// Case #5: 560963525

// notice the beauty in this solution
// principle of inclusion exclusion 
// <https://math.stackexchange.com/questions/2498773/three-couples-sit-at-random-in-a-line-of-six-seats-probability-that-no-couple-s?rq=1>

// ans = 
// all factorial
//  - cases where one couple sit together
//  + cases where two couples sit together
//  - cases where three couples sit together
//  ..
//  m

// for each case:
// 	choose couple in mC(j) ways where j varies from 1 to m
// 	2^j ways to permute those couples
// 	consider each couple as one single seat - there will be j such seats
// 	  and 2n-j other seats, hence (2n-2j+j)! = (2n-j)! ways to permute.
// 	  2n: all seats 2j: seats taken by couple j: considering each couple as one seat
// therefore, mC(j) * 2^j * (2n-j)! for each j between 1 and m;

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first.first
#define se first.second
#define MOD 1000000007
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
typedef long long ll;
typedef unsigned long long ull;

ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){ll ans = (a%p + b%p)%p; return (ans+p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}

void fillfact(vector<ll>& fact, vector<ll> &invvec){
	fact[0] = 1; invvec[0] = 1;
	fact[1] = 1; invvec[1] = 1;
	forr(i,2,200001){
		fact[i] = mult(fact[i-1],i);
		invvec[i] = inv(fact[i]);
	}
}

vector<ll> fact(200005,0);
vector<ll> invvec(200005,0);

ll ncr(ll n, ll r){
	return (mult(fact[n],mult(invvec[r],invvec[n-r])));
}

int main(int argc, char const *argv[]){
	ull t,m,n;	
	fillfact(fact,invvec);
	cin>>t;
	for(int i=1; i<=t; ++i){
		cin>>n>>m;
		ll ans = 0; ll toggle = 1; ll twopow = 2;
		forr(j,0,m){
			ans = add(ans,toggle*(mult(twopow,mult(ncr(m,j+1),fact[(2*n)-j-1]))));
			toggle *= -1;
			twopow = mult(twopow,2);
		}
		cout<<"Case #"<<i<<": "<<add(fact[2*n],-ans)<<endl;
	}
	return 0;
}