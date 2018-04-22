// no need of bitset for set union I guess
// can directly add to set and take sizeof(set) in the end

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

#define pb push_back
#define mp make_pair

using namespace std;

const int MAX = 1000001;
const int sqrtMAX = 1001;

int main(){
	vector<int> primes;
	bool arr[MAX] = {};
	for(int i=2; i<sqrtMAX; ++i){
		if(arr[i] == 0){
			primes.pb(i);
			for(int j=i*i; j<MAX; j+=i)
				arr[j] = 1;
		}
	}
	for(int i = sqrtMAX; i<MAX; ++i)
		if(arr[i] == 0)
			primes.pb(i);

	int a,b, count = 0;
	while(scanf("%d %d", &a, &b) == 2){
		if(a == 0)
			break;
		bool pfa[MAX] = {}, pfb[MAX] = {};
		vector<int> pfaa, pfbb;
		bitset<MAX> aa = {}, bb = {};
		int c, ind = 0;
		// for a
		while(a != 1){
			c = 0;
			while(a % primes[ind] == 0){
				++c; a /= primes[ind];
			}
			if(c != 0){
				aa[primes[ind]] = 1;
				pfa[primes[ind]] = 1;
				pfaa.pb(c);
			}
			++ind;
		}
		ind = 0;
		// for b
		while(b != 1){
			c = 0;
			while(b % primes[ind] == 0){
				++c; b /= primes[ind];
			}
			if(c != 0){
				bb[primes[ind]] = 1;
				pfb[primes[ind]] = 1;
				pfbb.pb(c);
			}
			++ind;
		}
		int dist = 0, ac = -1, bc = -1, tempa, tempb;
		for(int it = 0; it < MAX; ++it){
			tempa = 0, tempb = 0;
			if(pfa[it] == 1){
				ac += 1; tempa = pfaa[ac];
			}
			if(pfb[it] == 1){
				bc += 1; tempb = pfbb[bc];
			}
			dist += abs(tempa - tempb);
		}
		aa |= bb;
		printf("%d. %lu:%d\n", ++count, aa.count(), dist);
	}
	return 0;
}