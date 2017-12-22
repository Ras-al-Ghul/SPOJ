// cryptic problem statement
// turned out to be vanilla LCS

#include <iostream>

#define MAX 2000

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	int Agnes[MAX+2], Tom[MAX+2];
	int i, j;
	while(ncases--){
		i = 0; Agnes[i++] = 0;
		while(true){
			scanf("%d", &Agnes[i++]);
			if(Agnes[i-1] == 0)
				break;
		}
		int bestsofar = 0;
		while(true){
			j = 0; Tom[j++] = 0;
			scanf("%d", &Tom[j++]);
			if(Tom[j-1] == 0)
				break;
			while(true){
				scanf("%d", &Tom[j++]);
				if(Tom[j-1] == 0)
					break;
			}
			int isize = i-1;
			int jsize = j-1;
			int arr[isize][jsize] = {};
			for(int k=1; k<isize; ++k){
				for(int l=1; l<jsize; ++l){
					if(Agnes[k] == Tom[l])
						arr[k][l] = arr[k-1][l-1] + 1;
					arr[k][l] = max(arr[k][l], arr[k-1][l]);
					arr[k][l] = max(arr[k][l], arr[k][l-1]);
				}
			}
			bestsofar = max(bestsofar, arr[isize-1][jsize-1]);
		}
		printf("%d\n", bestsofar);
	}
	return 0;
}