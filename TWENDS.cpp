#include <iostream>

const int MAX = 1000;
int arr[MAX];

using namespace std;

int dp(int dparr[][MAX][2], int begin, int end){
	if(dparr[begin][end][0] != 0)
		return dparr[begin][end][0];
	if(begin >= end){
		dparr[begin][end][1] = 0;
		return 0;
	}

	int newbegin1, newend1, newbegin2, newend2;
	newbegin1 = arr[begin+1]>=arr[end]?begin+2:begin+1;
	newend1 = arr[begin+1]>=arr[end]?end:end-1;
	int temp1 = arr[begin] + dp(dparr, newbegin1, newend1);
	newbegin2 = arr[begin]>=arr[end-1]?begin+1:begin;
	newend2 = arr[begin]>=arr[end-1]?end-1:end-2;
	int temp2 = arr[end] + dp(dparr, newbegin2, newend2);
	if(temp1>=temp2){
		dparr[begin][end][1] = (arr[begin+1]>=arr[end]?arr[begin+1]:arr[end]) + dparr[newbegin1][newend1][1];
	}
	else{
		dparr[begin][end][1] = (arr[begin]>=arr[end-1]?arr[begin]:arr[end-1]) + dparr[newbegin2][newend2][1];
	}
	return dparr[begin][end][0] = max(temp1, temp2);
}

int main(){
	int count = 1;
	while(true){
		int n; scanf("%d", &n);
		if(n==0)
			break;
		for(int i=0; i<n; ++i){
			scanf("%d", &arr[i]);
		}
		
		int dparr[MAX][MAX][2] = {};
		int dpans = dp(dparr, 0, n-1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", count++, dpans-dparr[0][n-1][1]);
	}
	return 0;
}