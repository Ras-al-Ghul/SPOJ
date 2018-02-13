// think of the underlying math if any
// here it was like:
// if the two coins belongs to the same person, the new one will be
// gained to hhb, or else it will belongs to lxh
// and lxh plays first
// so it is like ++ or -- gives +
// -+ or +- gives -
// you can see that odd number of - will always give -, even number will always give +
// and number of plus doesn't matter, you always consume + with a -, reduce total
// number by 1 to get a -, so that 'consuming' is a critical idea to reason as to
// why number of +'s doesn't affect the final outcome of whether last one remaining
// will be + or -

#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int pcount = 0, mcount = 0;
		for(int i=0; i<n; ++i){
			cin>>input;
			if(input[0] == 'l')
				mcount++;
			else
				pcount++;
		}
		if(mcount%2 != 0)
			printf("lxh\n");
		else
			printf("hhb\n");
	}
	return 0;
}