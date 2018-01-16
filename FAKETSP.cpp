#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double dist = 0;
	double oldx, oldy, x, y; char c;
	while(scanf("%c", &c) == 1){
		if(c == '('){
			scanf("%lf", &oldx);
			scanf("%c", &c);
			scanf("%lf", &oldy);
			break;
		}
	}
	while(scanf("%c", &c) == 1){
		if(c == '('){
			scanf("%lf", &x);
			scanf("%c", &c);
			scanf("%lf", &y);
			dist = dist + sqrt(pow(abs(x-oldx),2)+pow(abs(y-oldy),2));
			oldx = x; oldy = y;
			printf("The salesman has traveled a total of %.3lf kilometers.\n", dist);
		}
	}
	return 0;
}
