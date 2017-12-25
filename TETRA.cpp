#include <iostream>
#include <cmath>

using namespace std;

// volume of tetrahedron - messy formula
inline double volume(double u, double v, double w, double U, double V, double W){
	double u1, v1, w1;
	u1 = (v*v)+(w*w)-(U*U);
	v1 = (w*w)+(u*u)-(V*V);
	w1 = (u*u)+(v*v)-(W*W);
	return sqrt(4.0*(u*u)*(v*v)*(w*w) - (u*u)*(u1*u1) - (v*v)*(v1*v1) - (w*w)*(w1*w1) + (u1*v1*w1))/12.0;
}
// surface area of triangle - Herons formula
inline double surface(double a, double b, double c){
	return sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))/4.0;
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	double wx, wy, wz, xy, xz, yz, sur, rad;
	while(ncases--){
		scanf("%lf %lf %lf %lf %lf %lf", &wx, &wy, &wz, &xy, &xz, &yz);
		sur = surface(wx, wy, xy) + surface(wx, xz, wz) + surface(wy, yz, wz) + surface(xy, xz, yz);
		// r = 3*v/(a1+a2+a3+a4)
		rad = volume(wx, wy, wz, yz, xz, xy) * (3.0 / sur);
		printf("%.4lf\n", rad);
	}

	return 0;
}