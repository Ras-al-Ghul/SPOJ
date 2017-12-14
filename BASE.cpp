// interesting way to convert a base 10 number to any base
// mod by base to get last digit, divide by base to reduce to new number and repeat

#include <iostream>

using namespace std;

int main(){
	char num[8];
	int from, to;
	while(scanf("%s %d %d", num, &from, &to) == 3){
		int i = 0;

		unsigned long actualnum=0;i=-1;
		while(num[++i]!='\0'){
			if(num[i]<='9')
				actualnum=actualnum*from+num[i]-48;
			else
				actualnum=actualnum*from+num[i]-55;
		}
		char arr[8] = {}; arr[7] = '\0';
		i = 6;
		while(actualnum){
			if(i == -1)
				break;
			int temp = actualnum%to;
			if(temp < 10)
				arr[i--] = temp + 48;
			else
				arr[i--] = temp + 55;
			actualnum /= to;
		}
		if(actualnum)
			printf("  ERROR\n");
		else{
			while(i>=0){
				arr[i--] = ' ';
			}
			printf("%s\n", arr);
		}
	}

	return 0;
}