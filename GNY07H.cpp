// similar to M3TILE
// output fits in 32 bit int, hence MAX is 1700 found using trial and error
// <https://math.stackexchange.com/questions/664113/count-the-ways-to-fill-a-4-times-n-board-with-dominoes>
// so see how the last column or last two columns or last three columns can be made

// can also search on OEIS to get answer directly
// uncomment to see
// T: total number of ways
// space is the crossing point

// F:
// - -.
// - -.
// - ..
// - ..
// 2 up 2 down - and 2 because the dots can be made in two ways
// so totally 4*F

// T[i-2]
// - ..
// - ..
// - ..
// - ..
// nothing crosses case, two columns can be filled in 5 ways, hence into 5 times

// G
// - -.
// - -.
// - -.
// - -.
// all four rows cross, hence number of ways is just 1 way into T[i-3]

// H
// - -.
// - ..
// - ..
// - -.
// top and bottom row cross, so 1 way into (T[i-4] + itself - i.e. H[i-3])

// I
// -- ..
//  - -.
//  - -.
// -- ..
// middle two cross, so 1 way into (T[i-3] + H[i-2]) - depends on H, instead of itself

#include <iostream>

using namespace std;

const int MAX  = 1700;

int main(){
	int n, temp, T[MAX] = {}, F[MAX] = {}, G[MAX] = {}, H[MAX] = {}, I[MAX] = {};
	T[1] = 1; T[2] = 5;
	F[2] = 1;
	H[1] = 1; H[2] = 0;
	G[2] = 1;
	I[2] = 1;

	//memoise the values first
	for(int i=3; i<=MAX; i++){
		T[i] = (4*F[i-1]) + (5*T[i-2]) + G[i-1] + H[i-1] + I[i-1];
		F[i] = T[i-2] + F[i-1];
		G[i] = T[i-2];
		H[i] = T[i-3] + H[i-2];
		I[i] = H[i-1] + T[i-2];
	}
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &temp);
		printf("%d %d\n", i, T[temp]);
	}
	return 0;
}