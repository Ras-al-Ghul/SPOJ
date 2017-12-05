// <https://math.stackexchange.com/questions/266783/geometric-argument-as-to-why-the-cyclic-quadrilateral-has-the-maximal-area>
// <https://www.quora.com/Sphere-Online-Judge-SPOJ-In-the-problem-QUADAREA-why-does-my-program-give-a-wrong-answer-if-I-use-floats-but-a-correct-one-if-I-use-doubles>

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	double a, b, c, d, s;
	while(ncases--){
		cin>>a>>b>>c>>d;
		s = (a+b+c+d)/2;
		printf("%.2lf\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
	}
	return 0;
}