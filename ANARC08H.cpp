// <https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/>
#include <iostream>

using namespace std;

int main(){
	int n, d;
	while(true){
		scanf("%d %d", &n, &d);
		// if(n==0 and d==0)
		// 	break;
		// int i, count=1, index=1, start = 1;
		// int arr[n];
		// for(i=0; i<n; ++i)
		// 	arr[i] = i+1;
		// bool loopflag = true;
		// int tempnum = arr[0];
		// while(true){
		// 	if(arr[index] != -1){
		// 		++count;
		// 		if(arr[index] == tempnum and count == 2)
		// 			break;
		// 	}
		// 	if(count==d){
		// 		arr[index] = -1; count=1;
		// 		while(arr[index] == -1){
		// 			index = (index+1)%n;
		// 		}
		// 		tempnum = arr[index];
		// 	}
		// 	index = (index+1)%n;
		// }
		// printf("%d %d %d\n", n, d, arr[index]);
		
		if(n==0 and d==0)
			break;
		
		int r=0, i=2;
		while(i<=n){
			r = (r+d)%i;
			i+=1;
		}
		printf("%d %d %d\n", n, d, r+1);
	}

	return 0;
}