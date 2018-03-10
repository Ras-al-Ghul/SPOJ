#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main(){
	int n; scanf("%d", &n);
	while(n--){
		int a; scanf("%d", &a); int arr1[a];
		for(int i=0; i<a; ++i)
			scanf("%d", &arr1[i]);
		int b; scanf("%d", &b); int arr2[b];
		for(int i=0; i<b; ++i)
			scanf("%d", &arr2[i]);

		sort(arr1, arr1+a); sort(arr2, arr2+b);

		int ans = INT_MAX;
		int fir = 0, sec = 0;
		while(fir<a and sec<b){
			ans = min(ans, abs(arr1[fir] - arr2[sec]));
			if(fir+1<a and sec+1<b)
				if(abs(arr1[fir+1]-arr2[sec])<=abs(arr1[fir]-arr2[sec+1]))
					++fir;
				else
					++sec;
			else
				break;
		}
		if(fir+1 == a)
			while(sec<b){
				ans = min(ans,abs(arr1[fir] - arr2[sec++]));
			}
		else if(sec+1 == b)
			while(fir<a){
				ans = min(ans,abs(arr1[fir++] - arr2[sec]));
			}
		printf("%d\n", ans);

	}
	return 0;
}