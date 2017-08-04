// do not like these floating point questions
// double format specifier is %lf

#include <iostream>

#define M_PII 3.14159 

using namespace std;

int main(){
	double length;
	double ans;
	while(true){
		scanf("%lf", &length);
		if(length == 0)
			break;
		printf("%.2lf\n", ((double)(length * length)/(double)(M_PII * 2)));
	}
	return 0;
}