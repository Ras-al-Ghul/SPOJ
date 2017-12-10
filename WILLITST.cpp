// workout pattern till num=10 and reason

#include <iostream>
#include <cmath>

#define ull unsigned long long

using namespace std;

int main(){
	ull num;
	scanf("%llu", &num);
	ull log2num = log2(num);
	if(pow(2,log2num) == num)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;
	return 0;
}