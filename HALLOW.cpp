// my first thought without reading the constraints was to think that
// sum for all possible subsets would be necessary - like for all we know,
// there could be a subset formed out of any of the elements and we would need
// to look into all - my dp was iterate through all subsets, use sum of smaller
// subsets to calculate sum of larger ones - i.e. store sum of subsets seen till now
// like if current subset is 11001, find sum of 1+1001 and store it, 1001 being smaller,
// we would already know its answer - but then again finding MSB, making rest 0, taking
// AND, etc. is all this necessarily a speedup? Also 1<=c<=n<=100000, so dp[1<<n] will segfault

// look at subset sum problem from MAIN72
// <https://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/>
// finding modsum is a bit of extension <https://www.geeksforgeeks.org/subset-sum-divisible-m/>
// if c<=n, then pigeonhole principle, such a modsum always exists
// but if c>n, then we have to use extension of subset sum idea
// have bool dp[c] if mod c sum is needed
// for each of the n elements (1<=j<=n), see what new mods get created, from preexisting mods
// as well as the element itself (i.e. if dp[i] for 1<=i<=c is true, i.e. if such a mod is already possible,
// then if current dp[(i+arr[j])%m] == false, make it true, a new mod gets created)
// take care to count each set element once, i.e. use bool temp[m], copy it to dp[m], after each iteration
// Ultimately, we have to answer the question of dp[0] i.e. whether (some subset mod c) = 0 exists
// This is a O(nc) solution which will again time out given our constraints

// look at pigeonhole argument
// <https://www.quora.com/Given-N-numbers-how-can-you-choose-a-non-empty-subset-of-the-numbers-so-that-the-sum-of-the-subset-is-a-multiple-of-N>
// Given N numbers, how can you choose a non-empty subset of the numbers so that the sum of the subset is a multiple of N?
// Using this, you can easily code the solution
// just take care to keep moding the sequential sum


#include <iostream>
#include <map>

#define mp make_pair

using namespace std;

// int gbp(int n) {
// 	 // return log(2) of n
// 	 unsigned int m;
// 	 m = n;
// 	 m = m | m >> 1;
// 	 m = m | m >> 2;
// 	 m = m | m >> 4;
// 	 m = m | m >> 8;
// 	 m = m | m >> 16;
// 	 m = m & ((~m >> 1)^0x80000000);
// 	// printf("m is now %d\n", m);
// 	return m;
// }

// int main(){
// 	int c, n;
// 	while(true){
// 		scanf("%d %d", &c, &n);
// 		if(c == 0)break;
		
// 		int dp[1<<n] = {}, temp, i, t;
		
// 		int arr[n];
// 		for(i=0; i<n; ++i)
// 			scanf("%d", &arr[i]);

// 		for(i=0; i<n; ++i)
// 			dp[1<<i] = arr[i];

// 		bool flag = false;
// 		for(i=1; i<(1<<n); ++i){
// 			if(dp[i] != 0){
// 				if(dp[i]%c == 0){
// 					flag = true;
// 					break;
// 				}
// 				continue;
// 			}
// 			temp = gbp(i);
// 			dp[i] = dp[temp] + dp[((temp-1)&i)];
// 			if(dp[i]%c == 0){
// 				flag = true;
// 				break;
// 			}
// 		}
		
// 		if(flag){
// 			t = i;
// 			for(i=0; i<n; ++i){
// 				temp = (1&t);
// 				if(temp)
// 					printf("%d ", i+1);
// 				t = (t>>1);
// 			}
// 			printf("\n");
// 		}
// 		else
// 			printf("no sweets\n");
// 	}
// 	return 0;
// }

int main(){
	int c, n;
	
	while(true){
		scanf("%d %d", &c, &n);
		if(c == 0)break;
		
		// stores sum of sequence
		map<int,int> seqsum;
		auto it = seqsum.end();

		int arr[n], i, sum = 0, j;
		for(i=0; i<n; ++i)
			scanf("%d", &arr[i]);

		seqsum.insert(mp(0,-1));
		for(i=0; i<n; ++i){
			sum += (arr[i]);
			sum %= c;
			it = seqsum.find(sum%c);
			if(it != seqsum.end())
				break;
			else
				seqsum.insert(mp(sum%c,i));
		}

		for(j=it->second+1; j<=i; ++j)
			printf("%d ", j+1);
		printf("\n");
	}

	return 0;
}