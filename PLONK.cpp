// idea was right, but I used the wrong statistical measure
// mean isn't the answer - median is the answer
// <https://apps.topcoder.com/forums/?module=Thread&threadID=513921&mc=15&view=tree>
// also remember kth order statistic - find kth element in sorted list given unsorted array
// O(n) average algo is possible - QSELECT
// we know pivot is in correct position, recurse in required partition
// continue till pivot is kth element

#include <iostream>
#include <algorithm>

using namespace std;

// int main(){
// 	int t, n; scanf("%d", &t);
// 	while(t--){
// 		scanf("%d", &n);
// 		int arr[n][2], sumx = 0, sumy = 0;

// 		for(int i=0; i<n; ++i){
// 			scanf("%d %d", &arr[i][0], &arr[i][1]);
// 			sumx += arr[i][0]; sumy += arr[i][1];
// 		}

// 		double meanx = sumx/double(n), meany = sumy/double(n);
// 		double temp, mins = double(INT_MAX); int minind = -1;
// 		for(int i=0; i<n; ++i){
// 			temp = abs(arr[i][0] - meanx) + abs(arr[i][1] - meany);
// 			if(temp < mins){
// 				mins = temp;
// 				minind = i;
// 			}
// 		}
// 		int totaldist = 0;
// 		for(int i=0; i<n; ++i)
// 			totaldist += (abs(arr[i][0]-arr[minind][0])+abs(arr[i][1]-arr[minind][1]));
		
// 		printf("%d\n", totaldist);
// 	}
// 	return 0;
// }

int main(){
	int t, n; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		// first holds values, second holds index
		pair<int,int> arrx[n], arry[n];

		for(int i=0; i<n; ++i){
			scanf("%d %d", &arrx[i].first, &arry[i].first);
			arrx[i].second = i; arry[i].second = i;
		}

		// helps in calculating distances in O(1) time
		sort(arrx, arrx+n); sort(arry, arry+n);
		int sumx = 0, sumy = 0;
		// calculate distance sum to leftmost/lowest/bottommost
		for(int i=1; i<n; ++i){
			sumx += (arrx[i].first - arrx[0].first);
			sumy += (arry[i].first - arry[0].first);
		}
		
		int distarr[n] = {};
		// notice that distances at 'respective indices' need to be incremented
		distarr[arrx[0].second] += sumx;
		distarr[arry[0].second] += sumy;
		int prevx = sumx, prevy = sumy, xdiff, ydiff;
		// trying to find better mindist values
		for(int i=1; i<n; ++i){
			// difference between ith and i-1th xvalue in sorted list
			xdiff = arrx[i].first - arrx[i-1].first;
			// for every element to the right, you have to subtract the xdiff
			// notice that this is only possible because of sorting
			sumx -= ((n-i-1)*xdiff);
			// for every element to the left, you have to add the xdiff
			sumx += ((i-1)*xdiff);
			// update distance at relevant index
			distarr[arrx[i].second] += sumx;

			ydiff = arry[i].first - arry[i-1].first;
			sumy -= ((n-i-1)*ydiff);
			sumy += ((i-1)*ydiff);
			distarr[arry[i].second] += sumy;
		}
		// find minimum of all distances		
		int mindist = sumx + sumy;
		for(int i=0; i<n; ++i)
			mindist = min(mindist, distarr[i]);

		printf("%d\n", mindist);
	}
	return 0;
}
