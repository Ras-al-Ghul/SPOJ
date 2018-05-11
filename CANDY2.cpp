// on working out a few examples, it became clear that a greedy solution would not work
// so solution is as follows:
// for each flavor (C,S,B), pick the three different priority bags
// you can do that through sort or through finding three greatest elements in list in O(n) time using if else if
// which is what is done below
// now a solution is guaranteed to exist in this 3x3x3 solution space through which you can brute force
// even if there is tie i.e. eg if C and S both prefer say bag 5 for first spot,
// still since you have three different bags for each flavor, you can break tie optimally by
// bruteforcing through this size 27 solution space

#include <iostream>
#include <climits>

using namespace std;

int main(){
	int n, i, j, k, l, sumc = 0, sums = 0, sumb = 0; scanf("%d", &n);
	int maxc[3] = {}, maxci[3], maxs[3] = {}, maxsi[3], maxb[3] = {}, maxbi[3];
	for(i=0; i<n; ++i){
		scanf("%d %d %d", &j, &k, &l);
		sumc += j; sums += k; sumb += l;
		if(j >= maxc[0]){
			maxc[2] = maxc[1]; maxci[2] = maxci[1];
			maxc[1] = maxc[0]; maxci[1] = maxci[0];
			maxc[0] = j; maxci[0] = i;
		}
		else if(j >= maxc[1]){
			maxc[2] = maxc[1]; maxci[2] = maxci[1];
			maxc[1] = j; maxci[1] = i;
		}
		else if(j >= maxc[2]){
			maxc[2] = j; maxci[2] = i;
		}
		if(k >= maxs[0]){
			maxs[2] = maxs[1]; maxsi[2] = maxsi[1];
			maxs[1] = maxs[0]; maxsi[1] = maxsi[0];
			maxs[0] = k; maxsi[0] = i;
		}
		else if(k >= maxs[1]){
			maxs[2] = maxs[1]; maxsi[2] = maxsi[1];
			maxs[1] = k; maxsi[1] = i;
		}
		else if(k >= maxs[2]){
			maxs[2] = k; maxsi[2] = i;
		}
		if(l >= maxb[0]){
			maxb[2] = maxb[1]; maxbi[2] = maxbi[1];
			maxb[1] = maxb[0]; maxbi[1] = maxbi[0];
			maxb[0] = l; maxbi[0] = i;
		}
		else if(l >= maxb[1]){
			maxb[2] = maxb[1]; maxbi[2] = maxbi[1];
			maxb[1] = l; maxbi[1] = i;
		}
		else if(l >= maxb[2]){
			maxb[2] = l; maxbi[2] = i;
		}
	}
	int ans = INT_MAX, ind[3];
	for(i=0; i<3; ++i){
		for(j=0; j<3; ++j){
			if(maxsi[j] == maxci[i])
				continue;
			for(k=0; k<3; ++k){
				if(maxbi[k] == maxsi[j] or maxbi[k] == maxci[i])
					continue;
				l = (sumc-maxc[i]) + (sums-maxs[j]) + (sumb-maxb[k]);
				if(l<ans){
					ans = l;
					ind[0] = maxci[i]; ind[1] = maxsi[j]; ind[2] = maxbi[k];
				}
			}
		}
	}
	printf("%d\n%d\n%d\n", ind[0], ind[1], ind[2]);
	return 0;
}