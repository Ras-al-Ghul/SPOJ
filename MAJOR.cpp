// Boyer Moore algorithm can also be used
// <https://www.geeksforgeeks.org/majority-element/>
// basic idea of the algorithm is if we cancel out each occurrence
// of an element e with all the other elements that are different
// from e then e will exist till end if it is a majority element

#include <iostream>

using namespace std;

int main(){
	int ncases, n, temp, transmit;
	scanf("%d", &ncases);
	while(ncases--){
		scanf("%d", &n);
		int arr[2001] = {};
		transmit = -2000;
		for(int i=0; i<n; ++i){
			scanf("%d", &temp);
			arr[temp+1000] += 1;
			if(arr[temp+1000] > (n/2))
				transmit = temp;
		}
		if(transmit != -2000)
			cout<<"YES "<<transmit<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}