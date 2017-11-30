// judging the difficulty level of a problem can be tough
// in this case I looked at steepest descent, conjugate gradient, etc.
// even Cramer's rule
// <https://en.wikipedia.org/wiki/Lagrange_polynomial>

// this was because the language in the problem was slightly deceiving
// for instance it said that the polynomial coefficients could be fractions, etc.
// also nowhere was it mentioned that the sequence was non decreasing
// again, this method that they have in mind, won't work for Fibonacci sequence
// more constraints are to be given

// again it is very important to gauge the level of the questions depending on the contest

// in such cases, if you're unsure about the method, try it on all of the test cases
// especially the tough ones, if it works for all, then your hypothesis might be correct

// method of successive differences, forward differences table
// this should come to mind when sequence is continuous i.e. for f(i), f(i+1), f(i+2), etc. given in order
// cannot use if f(i), f(i+5), f(i+x), etc. are given
// don't forget to use delete after using new in C++

#include <iostream>

using namespace std;

int main(){
	int numoftestcases;
	scanf("%d", &numoftestcases);

	int numofterms, nextterms;
	int *arr;
	int **arrofarrs;
	while(numoftestcases--){
		scanf("%d %d", &numofterms, &nextterms);
		arr = new int[numofterms + nextterms];
		for(int i=0; i<numofterms; i++){
			scanf("%d", &arr[i]);
		}
		arrofarrs = new int*[numofterms];
		arrofarrs[0] = arr;

		for(int i=1; i<numofterms; i++){
			arrofarrs[i] = new int[numofterms + nextterms - i];
			for(int j=0; j<(numofterms-i); j++){
				arrofarrs[i][j] = arrofarrs[i-1][j+1] - arrofarrs[i-1][j];
			}
		}

		for(int j=numofterms-(numofterms-1); j<(numofterms-(numofterms-1)+nextterms); j++){
			arrofarrs[numofterms-1][j] = arrofarrs[numofterms-1][0];
		}
		for(int i=((numofterms-1) - 1); i>=0; i--){
			for(int j=(numofterms-i); j<(numofterms-i+nextterms); j++){
				arrofarrs[i][j] = arrofarrs[i][j-1] + arrofarrs[i+1][j-1];
			}
			delete[] arrofarrs[i+1];
		}

		for(int i=numofterms; i<numofterms+nextterms; i++){
			printf("%d ", arrofarrs[0][i]);
		}
		delete[] arr;
		printf("\n");
	}

	return 0;
}
