// 0 0 0 0 2 3 4 5 is the cleverest fricking edge case
// this problem was all about handling edge cases

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int e, f, s, m, ed, fd, sd, md;
	while(scanf("%d %d %d %d %d %d %d %d", &e, &f, &s, &m, &ed, &fd, &sd, &md) == 8){
		if(e == -1)
			break;
		if(e == 0 and f == 0 and s == 0 and m == 0){
			printf("0 0 0 0\n");
			continue;
		}
		int flag = 0; float maxcakes = 0;
		if(e/float(ed) > maxcakes){
			maxcakes = e/float(ed); flag = 1;
		}
		if(f/float(fd) > maxcakes){
			maxcakes = f/float(fd); flag = 2;
		}
		if(s/float(sd) > maxcakes){
			maxcakes = s/float(sd); flag = 3;
		}
		if(m/float(md) > maxcakes){
			maxcakes = m/float(md); flag = 4;
		}

		int newmaxcakes = int(maxcakes);

		switch(flag){
			case 1:
				if(e%ed)
					newmaxcakes += 1;
				break;
			case 2:
				if(f%fd)
					newmaxcakes += 1;
				break;
			case 3:
				if(s%sd)
					newmaxcakes += 1;
				break;
			case 4:
				if(m%md)
					newmaxcakes += 1;
				break;
			default:
				newmaxcakes = 1;
		}
		printf("%d %d %d %d\n", (newmaxcakes*ed) - e, (newmaxcakes*fd) - f, (newmaxcakes*sd) - s, (newmaxcakes*md) - m);
	}
	return 0;
}