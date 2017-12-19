// <https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/>
// <http://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/>
// so the process to think about this is as follows -
//          c1c2c3
// person 1: 1 1 0
// person 2: 0 1 1
// person 3: 1 0 1
// first step: brute force all possible combinations
// a systematic way to do that is backtracking
// can easily count the number of ways with this method
// 1-->2-->3
// 3-->1-->2
// 2 ways
// so you need two variables to keep track of state
// one will tell which person is in consideration now, other will tell which class is in consideration
// so since time limit is less, we will need better than backtrack --> implies DP
// start with top down DP with state
// mask will denote which students have already been alloted, i will denote which class
// i means 0 to i-1 classes are done
// two possibilities for each i at given mask - 
// countways(mask, i) = countways(mask, i+1) + sum(countways(mask|(1<<j), i+1) for each j which can do task i)
// we need not assign this task OR we can assign current class i to student mask+1 at j

// so for each (mask, i), we need answer of (mask, i+1), (mask|j, i+1)
// bottom up will be in reverse direction
// in our problem since every student will need to be assigned one class,
// we can remove i from state - we can get i from mask as follows:
// i = number of set bits in mask --> the next class is to be alloted to this student
// we cannot do countways(mask, i+1) i.e. move on without assigning as there should be a 1-1 map

// so countways(mask) = sum(countways(mask|(1<<j)) for each j that can do task i where i is number of set bits in mask)

// since bottom up dp needs filling in reverse order,
// we need to fill like:
// 111
// 110, 101, 011,
// 100, 010, 001
// 000
// where each element in one row depends on elements in previous row
// 7
// 6 5 3
// 4 2 1
// 0
// but notice that 7 6 5 4 3 2 1 can also be the order, because:
// 4 depends on 5 and 6 which are already filled - this simplifies things
// 100 depends on 101 and 110 - this means:
// class 1 is allocated to person 3, class 2 can be allocated to person 1 (101) or person 2 (110)
// where (101) in turn depends on (111) - class 1 and 2 allocated to person 1 and 3, how many ways can class 3 be allocated to person 2?
// 1 way
// (101) = 1
// (110) = 0 (because class three cannot be allocated to person 1)
// (100) = 1+0 = 1
// finally
// (000) = (100) + (010) + (001)
// but (010) = 0 because class 1 cannot be allocated to person 2

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int count_set_bits(long n){
	int count = 0;
	while(n){
		count += (n & 1);
		n>>=1;
	}
	return count;
}

int main(){
	int c;
	scanf("%d", &c);
	while(c--){
		int n;
		scanf("%d", &n);
		long cost[n][n];
		for(long i=0; i<n; ++i){
			for(long j=0; j<n; ++j){
				scanf("%ld", &cost[i][j]);
			}
		}
		
		long dp[long(pow(2,n))] = {};
		
		dp[long(pow(2,n))-1] = 1;
		long ans;
		for(long i=long(pow(2,n))-2; i>=0; --i){
			int x = count_set_bits(i);
			ans = 0;
			for(int j=0; j<n; ++j){
				if((i&(1<<j)) == 0){
					if(cost[x][j]){
						ans += dp[i|(1<<j)];
					}
				}
			}
			dp[i] = ans;
		}
		printf("%ld\n", dp[0]);
	}
	return 0;
}