from math import log2, floor

def gcd(a, b):
	if(a<b):
		temp = b
		b = a
		a = temp
	while (b != 0):
		temp = b
		b = a%b
		a = temp
	return a

def main():
	while(1):
		n = int(input())
		if(n == 0):
			break
		level = floor(log2(n))
		num, den = 1, 1
		cur = 1<<level
		temp = cur-(cur+cur-1-n)
		count = 1
		while(level):
			tempnum = (1<<(level-1))
			level -= 1
			if(temp<=tempnum):
				num = num
				den = num+den
			else:
				den = den
				num = num+den
			if(temp>tempnum):
				temp-=tempnum
		gcdab = gcd(num, den)
		print(str(floor(num/gcdab))+"/"+str(floor(den/gcdab)))
	
if __name__ == '__main__':
	main()
