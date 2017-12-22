# frustrating
# many unneeded WA's because I wasn't looking into the fact that number of test cases were given
# also, test for perfect power from my cryptographic musings code wasn't needed
# even Wiki page doesn't mention it
# <https://math.stackexchange.com/questions/1470801/why-does-miller-rabin-algorithm-check-for-perfect-powers>
# overflow may occur in C++ if we multiply two longs and try to store in long long
# <https://stackoverflow.com/questions/17642689/miller-rabin-spoj-wa>

import random
_mrpt_num_trials = 25  # number of bases to test

def is_probable_prime(n):
    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n - 1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2 ** s * d == n - 1)

    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2 ** i * d, n) == n - 1:
                return False
        return True  

    for _ in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False

    return True  

from random import randrange
from math import sqrt, floor
from fractions import gcd

def MillerRabin(N, t = 20):

	if(N == 2):
		return True

	if (N % 2 == 0 or N < 2):
		return False

	# perfect power
	# for i in xrange(3, long(sqrt(N))):
	# 	tmp = 1
	# 	while tmp < N:
	# 		tmp = tmp * i
	# 		if(tmp == N):
	# 			return False

	# compute r, u
	r, u = 0, N-1

	while u % 2 == 0:
		r += 1
		u /= 2

	# loop 
	for i in xrange(t):
		a = randrange(1, N - 1)
		if gcd(N, a) != 1:
			return False
		# strong witness
		x = pow(a, u, N)
		if x == 1 or x == N - 1:
			continue
		for j in xrange(r - 1):
			x = pow(x, 2, N)
			if x == N - 1:
				break
		else:
			return False
	# prime
	return True

def main():
	for i in range(int(input())):
	    a = int(input())
	    if MillerRabin(a):
	        print("YES")
	    else:
	        print("NO")
	
# def main():
# 	for i in range(int(input())):
# 	    a = int(input())
# 	    if is_probable_prime(a):
# 	        print("YES")
# 	    else:
# 	        print("NO")

if __name__ == '__main__':
	main()