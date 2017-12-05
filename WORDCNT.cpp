// edge case and string handling

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string temp,line;

	int ncases;
	scanf("%d", &ncases);
	getline(cin, line);

	while(ncases--){
		int curlen = 0, counter = 0;
		int bestsofar = 0;
		
		getline(cin, line);
		
		stringstream ss(line);
		while(ss>>temp){
			if(temp.length() == curlen)
				counter += 1;
			else{
				bestsofar = max(bestsofar, counter);
				counter = 1;
				curlen = temp.length();
			}
		}
		cout<<max(bestsofar, counter)<<endl;
	}
	return 0;
}