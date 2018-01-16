#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool definitelyGreaterThan(float a, float b, float epsilon)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(float a, float b, float epsilon)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main(){
	string s;
	cin>>s;

	int zero = 0;
	int numzeroes = 0, numones = 0;
	float rotate, shoot;
	for(int i=0; i<s.length(); ++i){
		if(s[i] == '0'){
			++zero;
			if(s[(i+1)%s.length()] == '0'){
				++numzeroes;
			}
			else{
				++numones;
			}
		}
	}
	rotate = float(zero)/s.length();
	shoot = float(numzeroes)/(numzeroes+numones);

	if(definitelyGreaterThan(shoot,rotate,0.00001))
		printf("SHOOT\n");
	else if(definitelyLessThan(shoot,rotate,0.00001))
		printf("ROTATE\n");
	else
		printf("EQUAL\n");
	return 0;
}