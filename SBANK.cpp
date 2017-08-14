// thought it might involve hash tables and then sort
// but simple map did the job

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	map<string, long> A;
	int ncases;
	long accounts;
	scanf("%d", &ncases);
	string temp;
	map<string, long>::iterator it;
	while(ncases--){
		scanf("%ld", &accounts);
		getline(cin, temp);
		while(accounts--){
			getline(cin, temp);
			it = A.find(temp);
			if(it == A.end())
				A.insert(pair<string, long>(temp, 1));
			else
				it->second += 1;
		}

		for(it = A.begin(); it != A.end(); it++)
			cout<<it->first<<" "<<it->second<<endl;

		getline(cin, temp);
		if(ncases!=0)
			cout<<endl;

		A.clear();
	}
	return 0;
}