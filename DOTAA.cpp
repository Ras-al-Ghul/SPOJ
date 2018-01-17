// interesting logic
// the order of choosing heroes doesn't matter
// if we find count of heroes who survive to be >= m, then possible
// 1 <= m <= n was a lie

#include <iostream>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, m, d; scanf("%d %d %d", &n, &m, &d);
		int arr[n], temp;
		int count = 0;
		for(int i=0; i<n; ++i){
			scanf("%d", &arr[i]);
			count += (arr[i]/d);
		}

		if(count < m)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}