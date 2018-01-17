#include <iostream>
#include <cmath>

using namespace std;

bool essentiallyEqual(double a, double b, double epsilon=0.00001)
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main(){
	double a, b, s, m, n;
	while(true){
		scanf("%lf %lf %lf %lf %lf", &a, &b, &s, &m, &n);
		if(essentiallyEqual(a,0.0) and essentiallyEqual(b,0.0))
			break;

		double rhs = (b*n);
		double angle = atan((a*m)/rhs);

		double u = rhs/(s*cos(angle));
		angle = (angle*180)/M_PI;
		
		angle = 90.0-angle;
		printf("%.2lf %.2lf\n", angle, u);
	}
	return 0;
}