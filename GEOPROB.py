# enough if ratio remains the same I guess
# <https://apps.topcoder.com/forums/;jsessionid=5FBC9D76176657EA4B331B6CE3FA3538?module=Thread&threadID=632397&start=0&mc=3#1061249>

def main():
	n = 0
	n = int(raw_input())
	for i in xrange(n):
		arr = raw_input()
		arr = [int(x) for x in arr.split()]
		print ((arr[1]-arr[0])+(arr[1]-arr[2]))

if __name__ == '__main__':
	main()