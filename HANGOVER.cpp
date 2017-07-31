// this problem killed me
// floating point ops suck
// be very careful
// don't approximate unecessarily
// I'd used a lot of rounding operations, removed them in the end
// use simple brute force wherever possible
// use the below for comparisons

#include <iostream>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

map<int, int> values;

bool approximatelyEqual(float a, float b)
{
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * numeric_limits<float>::epsilon());
}

bool essentiallyEqual(float a, float b)
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * numeric_limits<float>::epsilon());
}

bool definitelyGreaterThan(float a, float b)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * numeric_limits<float>::epsilon());
}

bool definitelyLessThan(float a, float b)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * numeric_limits<float>::epsilon());
}

int main(){
	float number, sum;
	int numofcards;
	while(true){
		scanf("%f", &number);
		if(essentiallyEqual(number, 0.00f))
			break;
		sum = 1.0f/2;
		numofcards = 1;
		while(definitelyLessThan(sum, number)){
			numofcards += 1;
			sum += 1.0f/(numofcards+1);
		}
		cout<<numofcards<<" card(s)"<<endl;
	}
	return 0;
}