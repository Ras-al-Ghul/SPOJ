# no need to handle n^0 cases separately

def main():
	while(True):
		line = raw_input().split(" ")
		n, d = int(line[0]), int(line[1])
		if n == d == 0:
			return 0
		print n**d

if __name__ == '__main__':
	main()