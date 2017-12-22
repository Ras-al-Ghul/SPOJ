// two ways to solve this very important problem
// one is derivative of Matrix Chain Multiplication MCX
// <https://www.quora.com/How-do-I-solve-the-sweet-and-sour-rock-program-in-SPOJ>
// that was what I did
// the other is using just one array dp - very elegant
// <http://artofcompetitiveprogramming.blogspot.in/2016/01/spoj-sweet-and-sour-rock.html>
// <https://github.com/georgejsh/codeandsolutions/blob/master/rock.c>

#include <iostream>
#include <string>

using namespace std;

int main(){
	int t, n;
	string rock;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cin>>rock;
		// 0th index is number of ones, 1th index is score
		int arr[n][n][2] = {};
		if(rock[0] == '1'){
			arr[0][0][0] = 1; arr[0][0][1] = 1;
		}

		int col = 1;
		for(int i=1; i<n; ++i){
			int row = i;
			if(rock[row] == '1'){
				// for bottom row in every i, it is like base case
				arr[row][col][0] = 1; arr[row--][col][1] = 1;
			}
			else{
				row--;
			}
			for(; row>=0; --row){
				int len = col - row + 1;
				int ones = arr[row][col-1][0];
				if(rock[col] == '1')
					ones++;
				arr[row][col][0] = ones;
				arr[row][col][1] = max(arr[row+1][col][1], arr[row][col-1][1]);
				
				for(int k=col; k>row; k--){
					// for all possible k's
					arr[row][col][1] = max(arr[row][k-1][1]+arr[k][col][1],arr[row][col][1]);
				}
				// if number of ones is greater, then it is entire length
				if(ones > (len/2))
					arr[row][col][1] = len;
			}
			col++;
		}
		printf("%d\n", arr[0][n-1][1], n);
	}
	return 0;
}