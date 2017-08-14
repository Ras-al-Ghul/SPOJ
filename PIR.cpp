// 6 WAs - try different compilers too g++ 4.3.2 worked for this
// very very specific about ordering in line 18
// compare it to figure here <http://zobayer.blogspot.in/2009/11/volume-of-irregular-tetrahedron.html>

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long ncases;
	scanf("%ld", &ncases);
	double U, V, w, W, v, u;
	double UU, VV, WW;
	double temp;
	double ans;
	while(ncases--){
		scanf("%lf %lf %lf %lf %lf %lf", &u, &v, &w, &W, &V, &U);
		UU = pow(v,2)+pow(w,2)-pow(U,2);
		VV = pow(w,2)+pow(u,2)-pow(V,2);
		WW = pow(u,2)+pow(v,2)-pow(W,2);
		ans = sqrt(((4*(pow(u,2))*(pow(v,2))*(pow(w,2))) - ((pow(u,2))*(pow(UU,2))) - ((pow(v,2))*(pow(VV,2))) - ((pow(w,2))*(pow(WW,2))) + (UU*VV*WW)))/(double)(12.0);
		printf("%0.4lf\n", ans);
	}
	return 0;
}