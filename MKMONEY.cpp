#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int count = 1, times;
	double p, i, final;
	while(true){
		scanf("%lf %lf %d", &p, &i, &times);
		if(times == 0)
			break;
		final = p;
		for(int j=1; j<=times; ++j){
			double interest = (final*i)/(100*times);
			interest = floorf(interest*100)/100;
			final += interest;
		}
		printf("Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n", count++, p, i, times, final);
	}
	return 0;
}