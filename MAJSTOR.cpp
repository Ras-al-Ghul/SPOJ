#include <iostream>

using namespace std;

int main(){
	char s[52]; int nr, nf;
	scanf("%d%s%d", &nr, s, &nf);
	// 0 is R, 1 is P, 2 is S
	int a[nr][3] = {};
	char f[52];
	for(int i=0; i<nf; ++i){
		scanf("%s", f);
		for(int j=0; j<nr; ++j)
			if(f[j] == 'R')
				a[j][0]++;
			else if(f[j] == 'P')
				a[j][1]++;
			else
				a[j][2]++;
	}
	int sc = 0, sc_m = 0, m_d, md;
	for(int i=0; i<nr; ++i){
		if(s[i] == 'R')
			sc += ((a[i][2]*2) + (a[i][0]));
		else if(s[i] == 'P')
			sc += ((a[i][0]*2) + (a[i][1]));
		else
			sc += ((a[i][1]*2) + (a[i][2]));
		sc_m += max((a[i][0]*2)+a[i][1],max((a[i][1]*2)+a[i][2],(a[i][2]*2)+a[i][0]));
	}
	printf("%d\n%d\n", sc, sc_m);
	return 0;
}