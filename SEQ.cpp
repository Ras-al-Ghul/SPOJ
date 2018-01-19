// for modular exponentiation of matrices, read Ajay Somani's topcoder post
// <https://discuss.codechef.com/questions/2335/building-up-the-recurrence-matrix-to-compute-recurrences-in-ologn-time>
// <http://zobayer.blogspot.in/2010/11/matrix-exponentiation.html>
// specifically from FIBOSUM and RABBIT1
// <https://www.nayuki.io/page/fast-fibonacci-algorithms>
// why doesn't "doubling method" work here?
// maybe because matrix itself doesn't give answer like in Fibonacci sequence
// in Fibonacci sequence, base case is [1 1], hence essentially, matrix will give answer
// here base case is base[k] - the numbers a1, a2, a3, .. ak, not all 1's
// so necessarily have to multiply arr matrix with the base matrix
// [f(n), f(n-1), f(n-2)] = [[c1 c2 c3] [1 0 0] [0 1 0]] [a3 a2 a1] for k = 3
// look at LHS and RHS, now can raise [[][][]] matrix to n-k for k=3 to get f(n)
// <http://www.qc.edu.hk/math/Teaching_Learning/Nth%20power%20of%20a%20square%20matrix.pdf>
// <http://funloop.org/post/2017-04-14-computing-fibonacci-numbers.html>

#include <iostream>
#include <cstring>

const long MOD = 1000000000;

using namespace std;

long arr[10][10], base[10], x[10][10], y[10][10], k;

void matrixmul(bool toggle){
	long newm[k][k] = {};
	if(toggle == 0){
		// (x*y)%MOD and store in x
		for(int i=0; i<k; ++i){
			for(int j=0; j<k; ++j){
				for(int l=0; l<k; ++l){
					newm[i][l] = (newm[i][l] + (x[i][j]*y[j][l]))%MOD;
				}
			}
		}
		for(int i=0; i<k; ++i)
			for(int j=0; j<k; ++j)
				x[i][j] = newm[i][j];
	}
	else{
		// (y*y)%MOD and store in y
		for(int i=0; i<k; ++i){
			for(int j=0; j<k; ++j){
				for(int l=0; l<k; ++l){
					newm[i][l] = (newm[i][l] + (y[i][j]*y[j][l]))%MOD;
				}
			}
		}
		for(int i=0; i<k; ++i)
			for(int j=0; j<k; ++j)
				y[i][j] = newm[i][j];
	}
	return;
}

void modulo(long b){
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(x));
	for(int i=0; i<k; ++i)
		x[i][i] = 1;
	for(int i=0; i<k; ++i){
		y[0][i] = arr[0][i];
		if(i>=1)
			y[i][i-1] = 1;
	}
	
	while(b>0){
		if(b%2 == 1)
			// x = (x*y)%MOD
			matrixmul(0);
		// y = (y*y)%MOD
		matrixmul(1);
		b/=2;
	}
	return;
}

int main(){
	long c; scanf("%ld", &c);
	while(c--){
		scanf("%ld", &k);

		memset(arr, 0, sizeof(arr));
		
		for(int i=0; i<k; ++i)
			scanf("%ld", &base[i]);

		for(int i=0; i<k; ++i){
			scanf("%ld", &arr[0][i]);
			if(i>=1)
				arr[i][i-1] = 1;
		}
		
		long n; scanf("%ld", &n);
		
		if(n>k){
			modulo(n-k);

			long sum = 0;
			for(int i=0; i<k; ++i)
				sum = (sum + (x[0][i]*base[k-1-i]))%MOD;

			printf("%ld\n", sum);
		}
		else{
			printf("%ld\n", base[n-1]);
		}
	}

	return 0;
}