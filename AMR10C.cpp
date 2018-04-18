// Prime Factorization in O(logn) using sieve - store smallest prime factor for every number
// <https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/>
// see notes.txt

// you cannot do an approach like: check if 1 factor (number itself possible),
// if no, is 2 factor possible, if no is 3 possible?
// because to check 1 factor itself, you need to see if n is divisible
// by all perfect squares less than n/2 - which is too slow if you have to
// repeat for 2 factor possible, 3 factor possible etc.

// hence see factorizations/divisors and try to use prime factorization

// try to solve a couple of examples by hand and see that prime factorizatoin + bundling works

#include <iostream>
#include <vector>

// Maximum number possible for which you need prime factorization
#define MAXN 1000001

using namespace std;

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main(){
	int T, N; scanf("%d", &T);
    sieve();
	while(T--){
		scanf("%d", &N);
		vector<int> p = getFactorization(N);
        int cur = p[0], cnt = 0, maxcnt = 0;
		for(int i=0; i<p.size(); ++i){
			if(p[i] == cur)
                ++cnt;
            else{
                maxcnt = max(maxcnt,cnt);
                cur = p[i]; cnt=1;
            }
		}
        maxcnt = max(maxcnt,cnt);
		printf("%d\n", maxcnt);
	}
	return 0;
}