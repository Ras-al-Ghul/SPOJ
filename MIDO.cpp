// edge case handling
#include <iostream>

using namespace std;

int main(){
	int n; scanf("%d", &n);
	int t1m = 0, t1s = 0, t2m = 0, t2s = 0;
	int g1 = 0, g2 = 0;
	int who, min, sec, temp, prevm, prevs, prevwho; char c;
	scanf("%d %d%c%d", &who, &min, &c, &sec);
	prevm = min; prevs = sec; prevwho = who;
	if(who == 1) g1++; else g2++;
	n--;
	while(n--){
		scanf("%d %d%c%d", &who, &min, &c, &sec);
		if(g1 != g2){
			if(g1>g2){
				if(sec<prevs){
					temp = (sec+60) - prevs;
					t1s += temp;
					temp = (min-1) - prevm;
					t1m += temp;
				}
				else{
					temp = sec - prevs;
					t1s += temp;
					temp = min - prevm;
					t1m += temp;
				}
				if(t1s >= 60){
					++t1m; t1s -= 60;
				}
			}
			else if(g2>g1){
				if(sec<prevs){
					temp = (sec+60) - prevs;
					t2s += temp;
					temp = (min-1) - prevm;
					t2m += temp;
				}
				else{
					temp = sec - prevs;
					t2s += temp;
					temp = min - prevm;
					t2m += temp;
				}
				if(t2s >= 60){
					++t2m; t2s -= 60;
				}
			}
		}
		if(who == 1)
			++g1;
		else
			++g2;
		prevm = min, prevs = sec, prevwho = who;
	}
	if(g1 != g2){
		min = 47; sec = 60;
		if(g1>g2){
			temp = sec - prevs;
			t1s += temp;
			temp = min - prevm;
			t1m += temp;
			if(t1s >= 60){
				++t1m; t1s -= 60;
			}
		}
		else{
			temp = sec - prevs;
			t2s += temp;
			temp = min - prevm;
			t2m += temp;
			if(t2s >= 60){
				++t2m; t2s -= 60;
			}
		}
	}
	if(t1m<=9)
		printf("0");
	printf("%d:", t1m);
	if(t1s<=9)
		printf("0");
	printf("%d\n", t1s);
	if(t2m<=9)
		printf("0");
	printf("%d:", t2m);
	if(t2s<=9)
		printf("0");
	printf("%d\n", t2s);
	return 0;
}