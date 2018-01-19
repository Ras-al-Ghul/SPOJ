// lot of ideas from this problem
// 1) iter != primes.end() and (*iter) <= a
// 2) (*iter) <= a and iter != primes.end()
// Now, 2) was giving WA because iter = primes.end() and (*iter) was <= a
// very very tough to find out that this was the error

// find all divisors of natural number - they occur in pairs, so i=1, i<=sqrt(n), i and n/i pair
// find number of divisors of natural number - find prime factorization - 2^x*3^y*5^z.. - ans = (x+1) * (y+1) *...

// find prime factorization of given number - for all primes in range 2 to sqrt(n) (find using sieve), keep dividing by prime
// for all primes <= sqrt(n) will suffice, if prime>sqrt(n), means prime*prime = n --> so until sqrt(n) suffices
// other way is to store smallest prime factor for each number in an array - here it will need sieve until 1000000, hence not feasible
// but if queries are too many, it will give faster prime factorization
// n = n/smallest(n) where smallest(n) is smallest prime factor of n, keep doing until 1
// here we won't iterate over unneccasary primes - this is not necessarily faster than above solution, but
// faster than other geeks for geeks solution

// given all this, our problem is to find gcd(a,b) and number of divisors of gcd(a,b)

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

const int MAX = 1000000;

using namespace std;

int main(){
	vector<int> primes;
	bool arr[int(sqrt(MAX))+1] = {};
	// int smallest[int(sqrt(MAX+2))] = {};
	for(int i=2; i<=int(sqrt(MAX)); ++i){
		if(arr[i]==0){
			primes.push_back(i);
			// smallest[i] = i;
			for(int j=2; i*j<=int(sqrt(MAX)); ++j){
				arr[i*j] = 1;
				// if(not smallest[i*j])
				// 	smallest[i*j] = i;
			}
		}
	}
	// cout<<*(primes.begin())<<" "<<*(prev(primes.end()))<<endl;
	int t; scanf("%d", &t);
	while(t--){
		int a, b; scanf("%d %d", &a, &b);
		if(b>a){
			int temp = b; b = a; a = temp;
		}
		// bool primearr[MAX+2] = {};
		// int count = 0; int quo;
		// cout<<a<<endl;
		// while(a != 1){
		// 	quo = a/smallest[a];
		// 	if(primearr[quo]==0){
		// 		cout<<quo<<" quo"<<endl;
		// 		primearr[quo] = 1;
		// 		if(b%quo == 0)
		// 			++count;
		// 	}
		// 	if(primearr[smallest[a]]==0){
		// 		cout<<smallest[a]<<" smallest"<<endl;
		// 		primearr[smallest[a]] = 1;
		// 		if(b%smallest[a] == 0)
		// 			++count;
		// 	}
		// 	a = quo;
		// }
		// printf("%d\n\n", ++count);
		int temp;
		while(b != 0){
			temp = b; b = a%b; a = temp;
		}
		// a is gcd

		int count = 0, total = 1;
		// too slow
		// for(int i=1; i<=int(sqrt(a)); ++i){
		// 	if(a%i==0){
		// 		if(b%i==0){
		// 			++count;
		// 			// cout<<i<<endl;
		// 		}
		// 		if(a/i != i)
		// 			if(b%(a/i)==0){
		// 				// cout<<a/i<<endl;
		// 				++count;
		// 			}
		// 	}
		// }
		// cout<<*prev(primes.end())<<endl;
		auto iter = primes.begin();
		if(a == 1)
			total = 1;
		else{
			while(a != 0 and iter != primes.end() and (*iter) <= a){
				count = 0;
				while(a%(*iter) == 0){
					// cout<<a<<" "<<(*iter)<<endl;
					++count;
					a/=(*iter);
				}
				if(count != 0)
					total *= (count+1);
				++iter;
			}
			if(a>1)
				++total;
		}
		
		printf("%d\n", total);
	}
	return 0;
}