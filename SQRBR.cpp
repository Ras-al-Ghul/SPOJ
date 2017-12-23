// DP - bottom up - do not get stuck up with grid where i,j mean indices of string
// it may be grid where i,j mean something else - here let count(i,j) be the number
// of valid ways of filling the first i positions such that there are j more brackets
// of type '{' than of type '}' - count(0,1) = 1, build from there - count(0,i) = 0 for i>1 
// recurrence for i>0 is count(i,0) = count(i-1,1), count(i,j) = count(i-1,j-1) + count(i-1,j+1) for j>0
// but if you have to enforce '{' at position i, then,
// count(i,0) = 0 and count(i,j) = count(i-1,j-1) for j>0
// I was stuck up with grid index thinking - if it is too hard to formulate,
// then it means, grid string index meaning of the problem is wrong way to think
// about it, move on to try to find another dp state - one of them will most likely
// still be index of string, but the other variable in the state may mean something else
// <https://www.quora.com/How-to-solve-square-brackets-problem-on-SPOJ-SPOJ-SQRBR>
// notice that we get answer at count(2n, 0) - subproblems are disjoint
// i.e. count(i-1, j-1) and count(i-1, j+1) don't enumerate the same cases and hence
// can be just summed over like we don't want AUB = A+B-(AXnB)

#include <iostream>
#include <string>

using namespace std;

int main(){
	int ncases, n, k, temp;
	string braces;
	scanf("%d", &ncases);
	while(ncases--){
		scanf("%d %d", &n, &k);
		braces = "";
		for(int i=0; i<2*n; ++i)
			braces += '0';
		braces[0] = '{';
		for(int i=0; i<k; ++i){
			scanf("%d", &temp);
			braces[temp-1] = '{';
		}
		
		int len = 2*n;
		int arr[len][n+2] = {};

		arr[0][1] = 1;

		for(int i=1; i<len; ++i){
			if(braces[i] == '{')
				arr[i][0] = 0;
			else
				arr[i][0] = arr[i-1][1];
			for(int j=1; j<n+1; ++j){
				if(braces[i] == '{')
					arr[i][j] = arr[i-1][j-1];
				else
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1];
			}
		}

		// for(int i=0; i<len; ++i){
		// 	for(int j=0; j<n+1; ++j){
		// 		printf("%d ", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		printf("%d\n", arr[len-1][0]);
	}
	return 0;
}