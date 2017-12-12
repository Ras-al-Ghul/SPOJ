// DP was very slow, but perfectly working
// had to use stack - couldn't really use - only even number of {}'s condition
// Other interesting O(n^2) DP solution <https://abitofcs.blogspot.in/2014/10/a-bit-of-string-balancing-spoj-anarc09a.html>
// If you can't solve with grid method, try Mimino's classical approach and handle all cases

#include <iostream>
#include <string>
#include <stack>

#define MAX 20000

using namespace std;

int main(){
	string input;
	long ncases = 0;
	while(true){
		cin>>input;
		if(input[0] == '-')
			break;

		int len = input.length();

		// // DP gives TLE
		// int arr[len][len] = {};
		
		// arr[0][0] = 1;

		// for(int i=1; i<len; ++i){
		// 	int j = i;
		// 	for(int rows=i; rows>=0; --rows){
		// 		if(rows == j)
		// 			arr[rows][j] = MAX;
		// 		else{
		// 			if((j-rows)%2 == 0){
		// 				arr[rows][j] = MAX;
		// 				continue;
		// 			}
					
		// 			if(input[rows] == '{' and input[j] == '}')
		// 				arr[rows][j] = arr[rows+1][j-1];
		// 			else if(input[rows] == '}' and input[j] == '{')
		// 				arr[rows][j] = arr[rows+1][j-1] + 2;
		// 			else
		// 				arr[rows][j] = arr[rows+1][j-1] + 1;

		// 			for(int k=j-2; k>=rows; k-=2){
		// 				arr[rows][j] = min(arr[rows][j], (arr[rows][k] + arr[k+1][j]));
		// 			}

		// 		}
		// 	}
		// }
		// cout<<++ncases<<". "<<arr[0][len-1]<<endl;

		// use stack

		stack<char> braces;
		int count = 0;
		
		int i = 0;
		while(i<len){
			if(not braces.empty()){
				if(input[i] == '}'){
					braces.pop();
				}
				else{
					braces.push(input[i]);
				}
				++i;
			}
			else{
				if(input[i] == '{')
					braces.push(input[i]);
				else
					++count;
				++i;
			}
		}

		if(braces.size()%2 == 0)
			cout<<++ncases<<". "<<(count+braces.size())/2<<endl;
		else
			cout<<++ncases<<". "<<((count+braces.size())/2) + 1<<endl;
	}

	return 0;
}