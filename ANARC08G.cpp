// needs situational awareness
// a good understanding of why the solution is what it is needed
// see why the reduction of amount cash is happening - it is happening
// because of (2) below

// finding cycles approach etc. is a tough task - needs complicated Johnson's algorithm
// <https://www.youtube.com/watch?v=johyrWospv0>
// what is possible tho is:
// so between any two nodes (O(n^2)), if you find who owes what to whom,
// (you can find this out by checking outgoing and incoming links of two nodes)
// and then you can adjust the balance in shortest path - which is direct link
// and readjusting all other links
// in turn, it essentially means, doing the below actually.

// so let's decompose the situation step by step
// consider the following graph:
// D--30-->A
// -      ->
//  5     100
//   -   -
//   ->B
// D owes 30 to A, B owes 100 to A and D owes 5 to B

// so whatever happens,
// at D, outgoing: 35
// at A, incoming: 130
// at B, outgoing: 95
// in other words, at each node, what is owed or what is due, doesn't change --> (1)

// notice that in the above situation, 5 units of flow
// go from D to B to A, which is two hops
// instead it can go from D to in one hop, which is shorter
// in that case, we will have:
// D--35--> A <--95--B
// a reduction by 5 units overall
// remember DCOPs and finding shortest power supply route for given unit of flow
// from source to destination
// basically a MIN COST flow problem with direct link between each pair of nodes

// so for each unit of flow going anywhere in the network, it needs to go by shortest path
// and shortest path is direct link between any two nodes which ALWAYS EXISTS
// because anyone can pay anyone --> (2)

// from (1), we will have nodes which are in debit
// and nodes which are in credit
// from (2), nodes in debit will directly be linked to nodes in credit
// so overall, least amount of paper money used is EITHER of:
// sum of debits OR sum of credits

#include <iostream>

using namespace std;

int main(){
	int n, count = 0;;
	while(scanf("%d", &n) == 1){
		if(not n)
			break;
		int arr[n][n];
		int due[n] = {}, sum = 0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				scanf("%d", &arr[i][j]);
				sum += arr[i][j];
				due[j] -= arr[i][j];
				due[i] += arr[i][j];
			}
		}
		int ans = 0;
		for(int i=0; i<n; ++i){
			if(due[i] > 0)
				ans += due[i];
		}
		printf("%d. %d %d\n", ++count, sum, ans);
	}
	return 0;
}