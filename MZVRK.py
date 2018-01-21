from math import log2

hexDict = {
    '0':'0000', '1':'0001', '2':'0010', '3':'0011', '4':'0100', '5':'0101',
    '6':'0110', '7':'0111', '8':'1000', '9':'1001', 'a':'1010', 'b':'1011',
    'c':'1100', 'd':'1101', 'e':'1110', 'f':'1111', 'L':''}

def dec2bin(n):
    """
    A foolishly simple look-up method of getting binary string from an integer
    This happens to be faster than all other ways!!!
    """
    # =========================================================
    # create hex of int, remove '0x'. now for each hex char,
    # look up binary string, append in list and join at the end.
    # =========================================================
    return ''.join([hexDict[hstr] for hstr in hex(n)[2:]])

def main():
	line = input().split(" ")
	a, b = int(line[0]), int(line[1])
	# print(a, b)
	if a>b:
		temp = a
		a = b
		b = temp
	
	bin_a = dec2bin(a)
	bin_b = dec2bin(b)

	tempstr = "0"
	tempstr = "0" * (len(bin_b)-len(bin_a))
	bin_a = tempstr + bin_a

	# print(bin_a)
	# print(bin_b)

	ans = ((b*(b+1))//2) - (((a-1)*a)//2)
	# print(a,b,ans)

	size = b-a+1;
	left_a = int(log2(a));
	left_b = int(log2(b));

	times = 0
	cycle_len = 0
	state = 0
	cur = 0
	cur_pow_2 = 2
	
	for i in range(len(bin_b)-2,-1,-1):
		sums, times = 0, 0
		cycle_len = cur_pow_2*2
		state = 0
		temp = cur_pow_2
		# print("len ",i," ",len(bin_a))
		for j in range(i, len(bin_a)):
			state += (int(bin_a[j])*temp)
			temp = int(temp/2)

		# print(cur_pow_2,state)
		if state <= cur_pow_2:
			cur = cur_pow_2 - state + 1 + 1
			if cur <= size:
				times = int(min(size, cur+cur_pow_2-1-1)) - cur + 1
				ans -= int(cur_pow_2*times)
				sums += (cur_pow_2*times)
		else:
			times = cycle_len-state
			if times > size:
				times = size
			ans -= int(cur_pow_2*times)
			sums += (cur_pow_2*times)

		# print("times ",times," ",sums)
		times = 0
		cur = cycle_len-state+1
		if cur+cycle_len-1<=size:
			times = ((size-cur+1)//cycle_len)*(cur_pow_2-1)
			ans -= int(cur_pow_2*times)
			sums += (cur_pow_2*times)
			cur += (cycle_len*int((size-cur+1)/cycle_len))

		# print("times2",times,sums)
		times = 0
		if cur<=size:
			temp = size-cur+1
			if temp-1>cur_pow_2:
				times = temp-1 - cur_pow_2
				ans -= int(cur_pow_2*times)
				sums += (cur_pow_2*times)

		# print(cycle_len,state,cur,times)
		# print(sums,"\n")
		cur_pow_2 *= 2;

	print(int(ans))

if __name__ == '__main__':
	main()