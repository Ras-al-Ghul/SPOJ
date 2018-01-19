// the centroid divides median in ratio 2:1, use that to find area
// then complicated set of steps for second part of answer
// <http://harunurrashid-coding.blogspot.in/2014/08/problem-link-httpwww_19.html>
// topcoder method is even more complex
// <https://apps.topcoder.com/forums/;jsessionid=9A04473DB4E1409AF895F89C8DBA700F?module=Thread&threadID=630623&start=0&mc=7#1052585>

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n; scanf("%d", &n);
	while(n--){
		double a, dista, distb, distc;
		scanf("%lf %lf %lf %lf", &a, &dista, &distb, &distc);

		double area = (a*dista*3)/2;
		double b = (2*area)/(3*distb);
		double c = (2*area)/(3*distc);
		double RadCircum = (a*b*c)/(4*area);

		double HO = sqrt((9*RadCircum*RadCircum)-(a*a)-(b*b)-(c*c));
		double HG = (2*HO)/3;
		if(isnan(HG))
			HG = 0.0;
		printf("%.3lf %.3lf\n", area, HG);
	}
	return 0;
}