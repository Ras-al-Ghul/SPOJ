// <http://www.gogeometry.com/problem/p103_equilateral_triangle_heron_area_elearning.htm>

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	double d, e, f, s;
	while(t--){
		scanf("%lf %lf %lf", &d, &e, &f);	
		s = (d+e+f)/2;
		s = (((d*d*sqrt(3))/4)+((e*e*sqrt(3))/4)+((f*f*sqrt(3))/4)+(3*sqrt(s*(s-d)*(s-e)*(s-f))))/2;
		printf("%.2lf\n", s);
	}
	return 0;
}