// would never have figured it out on my own even if given hundred years
// <https://apps.topcoder.com/forums/?module=Thread&threadID=659936&start=0&mc=9#1181090>
// read that link thoroughly - last comment is gold

// Problem is solvable by using maths only . No need to find patterns on test cases.

// Observations :
// 1) clearly impossible to form a sequence for which modulus of sum of terms is greater then n*(n-1)/2. Equality is achieved when differences are all 1 or -1 e.g sequnce = 0 , 1 , 2 ,3 ... n-1

// Call this as base sequnce. ( with all diff as 1)

// 2) Any sequence can be considered as a derivative of this sequence under this operation- if diff between ai and ai-1 is 1 , make this diff -1 and keep difference of all other terms same. This is same as saying "pull down " the graph of sequence ai onwards by 2 units .

// 3) There is an invariant in this operation: parity of sum does not change. So ONLY those sums are possible to achieve which have same parity as n*(n-1)/2

// Not only this , this operation in itself is an algorithm to achieve this sequence. Think about it.

// Hope that helps !

// given n, k, find a one sequence starting from 0 that is n length long and sums to k
// beautiful in the sense that a solution is guaranteed to exist as long as
// required k lies within abs(n(n-1)/2) and is of same parity as n(n-1)/2
// once you assume that, then problem becomes slightly easier
// without that you have no clue when to output 'No' as an answer

#include <iostream>

using namespace std;

int sum( int x ) {
	return x * ( x - 1 ) / 2 ;
}

int main(){
	int t; scanf("%d", &t);
	int n, k;
	while(t--){
		scanf("%d %d", &n, &k);
		// range is obvious - if k is outside abs(sum(n)), then obv not possible
		// max possible sum in n length starting from 0 is n(n-1)/2
		if ( abs( k ) > sum( n ) || // check range
           ( abs( k ) & 1 ) != ( sum( n ) & 1 ) ) { // check parity
           	// parity is non obvious - as in one won't know that this is the thing to look for
           	// given parity of n(n-1)/2 and a length n sequence that generates it,
            // all other sequences can be considered "pull down"/"pull up" of that sequence and
            // the sequences that follow - everytime we do a pull down, we don't change
            // the parity of the sum of the new sequence, because we affect it by a multiple of two - which is even
            // odd +- even = odd and even +- even  = even - so it remains the same parity
            printf( "No\n" );
            continue;
        }
        // given that solution must exist if above is passed, we try to find
        // solutions from the base sequence - now all we need to do is given a number,
        // find out whether to increment by 1 or decrement by 1
        int i = 0;
        while ( n-- ) {
            printf( "%d\n", i );
            // printf("%d %d\n", k+n, sum(n));
        	// digit is already printed
        	// so we have n-1 length left - max sum possible in that is sum(n)
        	// notice the n--, hence it is no longer n, but n-1
        	// now we need k in n length and one digit is already printed
        	// hence we need k in n-1 length
        	// now max possible in n-1 length is sum(n) - n is n-1 as noted just above
        	// so if k+n > max possible, then we have no choice but to increment current number by 1
        	// sum(n) - because we are assuming current level to be 0 and start from 0
        	// assumption is valid because we no longer need original k, we have done k+n or k-n in
        	// each of the previous iterations, so that has also been adjusted already
        	// think of it as removing last number from given sequence
        	// i.e. the difference between max sum in sequence of length n and sequence of
        	// length n-1, both starting from 0 is n(n-1)/2 - (n-1)(n-2)/2 = n-1
        	// n-1 already done because of n--
        	// so k adjusted accordingly as k-=n or k+=n
        	// from link, we see that what we are looking for is a sequence which becomes equal to ideal
        	// sequence - i.e. all increasing or all decreasing - hence we compare with sum(n)
            
            // not >= because if k+n = sum(n), then it is possible to get k using n digits
            // no need of incrementing, can afford to decrement
            if ( k + n > sum( n ) )
            	// no choice but to increment i
            	// and obv, since we've added i, new required sum is less than k
                 k -= n, i++;
             // in all other cases can decrement i
             // and obv, since we've subtracted i, new required sum is more than k
            else k += n, i--;
            // printf("%d %d yo\n", n, k);
		}
		// ultimately, at each step, we are adjusting our sequence to match ideal sequence
		// both required sum - k and current starting value - 0 have been adjusted so that we can
		// consider series starting from 0
		// we are subtracting/adding to k by 'n' because we aim to match to ideal sequence
		if(t != 0)
			printf("\n");
		// see for this test case
		// 2
		// 5
		// 10
		// 5
		// 4
		// ANS:
		// 0 1 2 3 4 ideal case
		// 0 1 0 1 2 pull down by 1 at third number of sequence
	}
	return 0;
}