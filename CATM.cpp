#include <iostream>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int k;
	scanf("%d", &k);
	while(k--){
		int mx, my, c1x, c1y, c2x, c2y;
		scanf("%d %d %d %d %d %d", &mx, &my, &c1x, &c1y, &c2x, &c2y);
		int diffcx = abs(c1x-c2x), diffcy = abs(c1y-c2y);
		int diffmc1x = abs(c1x-mx), diffmc1y = abs(c1y-my);
		int diffmc2x = abs(c2x-mx), diffmc2y = abs(c2y-my);
		if((mx==c1x and my==c1y) or (mx==c2x and my==c2y)){
			printf("NO\n");
			continue;
		}
		if(diffcx == diffcy){
			if(diffmc1x == diffmc1y and diffmc2x == diffmc2y){
				if(diffmc1x < diffcx and diffmc2x < diffcx){
					printf("NO\n");
					continue;
				}
			}
		}
		printf("YES\n");
	}
	return 0;
}