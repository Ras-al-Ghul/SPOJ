// <https://www.geeksforgeeks.org/farey-sequence/>
// <https://en.wikipedia.org/wiki/Farey_sequence#Next_term>
// my solution was, generate fraction numbers with gcd = 1
// convert them to double, store along with fractional form, sort doubles
// turns out, can compare fractions x1/y1, x2/y2, both in simplest form, with x1*y2 < x2*y1
// that works by cross multiply rule - eg. compare 3/4 and 5/9
// 3*9/4*9 and 5*4/9*4 --> denominators become same, just compare numerators
// <https://mathbitsnotebook.com/JuniorMath/FractionsDecimals/FDcomparing.html>

// This is O(nlogn) or O(n^2logn) or O(nlogn^2)

// O(n) or O(n^2) solution is below:
// A term x/y can be recursively evaluated using previous two terms:
// x[n+2] = floor((y[n]+n) / y[n+1])x[n+1]– x[n]
// y[n+2] = floor((y[n]+n) / y[n+1])y[n+1]– y[n]

#include <iostream>
#include <vector>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

int main(){
	int t, n, m; scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		int arr[m];
		for(int i=0; i<m; ++i)
			scanf("%d", &arr[i]);

		vector<pair<int, int> > fareyseq;

		// we know first and second term
		double x1 = 0, y1 = 1, x2 = 1, y2 = n, x, y;
		fareyseq.pb(mp(x1,y1)); fareyseq.pb(mp(x2,y2));
		while(y != 1.0){
			x = floor((y1+n)/(y2))*x2 - x1;
			y = floor((y1+n)/(y2))*y2 - y1;
			fareyseq.pb(mp(x,y));
			// updates
			x1 = x2; y1 = y2;
			x2 = x; y2 = y;
		}
		for(int i=0; i<m; ++i){
			printf("%d/%d\n", fareyseq[arr[i]-1].first, fareyseq[arr[i]-1].second);
		}
	}
	return 0;
}