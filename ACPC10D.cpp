// notice the shit code I've written vs. the optimized code below
// the thing is, the case for some paths is contained in previous paths
// due to the rightward directionality of the graph - the key is to spot that
// that is way better than enumerating all possible cases from scratch

#include <iostream>

using namespace std;

int main(){
	int n, count = 1;
	int ans[3], cur[3], next[3];
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;

		scanf("%d %d %d", &ans[0], &ans[1], &ans[2]);
		scanf("%d %d %d", &cur[0], &cur[1], &cur[2]);
		// next[0] = cur[0] + ans[1];
		// next[1] = cur[1] + ans[1] + min(0, min(ans[2], cur[0]));
		// next[2] = cur[2] + ans[1] +  min(0, min(cur[0]+cur[1], min(cur[1], min(cur[1]+ans[2],ans[2]))));
		// ans[0] = next[0], ans[1] = next[1], ans[2] = next[2];
		// for(int i=2; i<n; ++i){
		// 	scanf("%d %d %d", &cur[0], &cur[1], &cur[2]);
		// 	next[0] = cur[0] + min(ans[0], min(ans[0]+ans[1], ans[1]));
		// 	next[1] = cur[1] + min(ans[0], min(ans[1], min(ans[2], min(ans[0]+cur[0], min(ans[0]+ans[1]+cur[0], min(ans[0]+ans[1], min(ans[0]+ans[1]+ans[2], min(ans[1]+cur[0], ans[1]+ans[2]))))))));
		// 	next[2] = cur[2] + min(ans[2], min(ans[1], min(ans[0]+ans[1], min(ans[0]+cur[1], min(ans[2]+cur[1], min(ans[1]+cur[1], min(ans[1]+ans[2], min(ans[1]+cur[0]+cur[1], min(ans[0]+cur[0]+cur[1], min(ans[0]+ans[1]+cur[0]+cur[1], min(ans[0]+ans[1]+cur[1], min(ans[0]+ans[1]+ans[2], ans[0]+ans[1]+ans[2]+cur[1]))))))))))));
		// 	ans[0] = next[0], ans[1] = next[1], ans[2] = next[2];
		// }
		// printf("%d. %d\n", count++, ans[1]);
		next[0] = cur[0] + ans[1];
		next[1] = cur[1] + min(ans[1], min(next[0], ans[1]+ans[2]));
		next[2] = cur[2] + min(ans[1], min(next[1], ans[1]+ans[2]));
		ans[0] = next[0], ans[1] = next[1], ans[2] = next[2];
		for(int i=2; i<n; ++i){
			scanf("%d %d %d", &cur[0], &cur[1], &cur[2]);
			next[0] = cur[0] + min(ans[0], ans[1]);
			next[1] = cur[1] + min(ans[0], min(ans[1], min(ans[2], next[0])));
			next[2] = cur[2] + min(ans[2], min(ans[1], next[1]));
			ans[0] = next[0], ans[1] = next[1], ans[2] = next[2];
		}
		printf("%d. %d\n", count++, ans[1]);
	}
	return 0;
}