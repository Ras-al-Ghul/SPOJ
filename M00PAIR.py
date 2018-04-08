from sys import stdin

def main():
	# 0th is 1, 1th is 01, 2th is 00
	# 1 gives 01 00 gives 01
	# 1 can be calculated using 2^
	# 01 gives 00
	# a already has 0 and 1 th values as base cases
	a = [[0,0,0],[1,1,0]]
	for i in xrange(2,1000):
		b = 1<<(i-1)
		c = a[i-1][0] + a[i-1][2]
		d = a[i-1][1]
		a += [[b,c,d]]
	for line in stdin:
		if line == '':
			break
		print a[int(line)][2]

if __name__ == '__main__':
	main()