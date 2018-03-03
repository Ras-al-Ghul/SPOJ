#include <iostream>
#include <cstdio>

using namespace std;

int pd, pm, py;
void getnext(int d, int m, int y){
	if(d<28){
		pd = d+1; pm = m; py = y;
		return;
	}
	if(d==28){
		if(m != 2){
			pd = d+1; pm = m; py = y;
			return;
		}
		else{
			if((y%4 == 0 and y%100 !=0) or y%400 == 0){
				pd = d+1; pm = m; py = y;
				return;
			}
			else{
				pd = 1; pm = m+1; py = y;
				return;
			}
		}
	}
	if(d==29){
		if(m == 2){
			pd = 1; pm = m+1; py = y;
			return;
		}
		else{
			pd = d+1; pm = m; py = y;
			return;
		}
	}
	if(d==30){
		if(m==4 || m==6 || m==9 || m==11){
			pd = 1; pm = m+1; py = y;
			return;
		}
		else{
			pd = d+1; pm = m; py = y;
			return;
		}
	}
	if(d==31){
		if(m==12){
			pd = 1; pm = 1; py = y+1;
			return;
		}
		else{
			pd = 1; pm = m+1; py = y;
			return;
		}
	}
}

int main(){
	int n;
	while(true){
		scanf("%d", &n); if(not n) break;
		int d, m, y, c; scanf("%d %d %d %d", &d, &m, &y, &c);
		int nd, nm, ny, nc;
		int numd = 0, numc = 0;
		if(n>=2){
			n--;
			while(n--){
				getnext(d,m,y);
				scanf("%d %d %d %d", &nd, &nm, &ny, &nc);
				if(pd==nd and pm==nm and py==ny){
					++numd; numc += (nc-c);
				}
				d = nd; m = nm; y = ny; c = nc;
			}
		}
		printf("%d %d\n", numd, numc);
	}
	return 0;
}