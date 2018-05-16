#include <iostream>
#include <vector>
#include <set>

// Maximum number possible for which you need prime factorization
#define MAXN 3000

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
bool getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
        if(ret.size() == 3)
            break;
    }
    if(ret.size() == 3)
        return true;
    else
        return false;
}

int main(){
	int T, N; scanf("%d", &T);
    sieve();
    vector<int> magic;
    // so that count starts from 1
    magic.push_back(0);
    for(int i=2; i<3000; ++i){
        bool ans = getFactorization(i);
        if(ans)
            magic.push_back(i);
    }
	while(T--){
		scanf("%d", &N);
        printf("%d\n", magic[N]);
	}
	return 0;
}