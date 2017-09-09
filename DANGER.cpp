// simple identify the pattern kind of problem
// go to the nearest two's power and do line number 37
// pattern: 1-1 2-1 3-3 4-1 5-3 6-5 7-7
// 8-1 9-3 10-5 11-7 12-9 13-11 14-13 15-15 16-1..

#include <iostream>
#include <string>

#define ull unsigned long long

using namespace std;

int main(){
	string input, ip;
	ull x, y, z, temp, num;
	while(true){
		getline(cin, input);
		x = input[0] - '0';
		y = input[1] - '0';
		z = input[3] - '0';

		if(!x and !y and !z)
			break;

		if(x == 0 and y == 1 and z == 0){
			printf("1\n");
			continue;
		}
		ip = ""; ip += input[0]; ip += input[1];
		for(temp=0;temp<z;++temp){
			ip+='0';
		}
		num = stoull(ip);
		temp = 2;
		while(temp - 1 < num)
			temp *= 2;
		cout<<num-(temp-1-num)<<endl;
	}
	return 0;
}