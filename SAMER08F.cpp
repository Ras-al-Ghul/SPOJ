// bitops may be faster, don;t know if it is even feasible though

#include <iostream>

using namespace std;

int main(){
	int n;
	int count, innercount;
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		count = 0;
		for(int i=1; i<=n; i++){
			innercount = 0;
			for(int j=0; i+j<=n; j+=1){
				innercount++;
			}
			count+=(innercount*innercount);
		}
		printf("%d\n", count);
	}

	return 0;
}