#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	string temp1, temp2;
	for(int j=1; j<=ncases; ++j){
		int nroutes;
		scanf("%d", &nroutes);

		map<string, string> table;
		map<string, int> occurences;

		for(int i=0; i<nroutes-1; ++i){
			cin>>temp1>>temp2;
			table.insert(pair<string, string>(temp1,temp2));
			occurences[temp1] += 1;
			occurences[temp2] += 1;
		}

		for(auto it = occurences.begin(); it != occurences.end(); ++it){
			if(it->second == 1 and table.find(it->first) != table.end())
				temp1 = it->first;
		}

		cout<<"Scenario #"<<j<<":"<<endl;
		auto it = table.find(temp1);
		for(int i=1; i<=nroutes-2; ++i){
			cout<<it->first<<endl;
			it = table.find(it->second);
		}
		cout<<it->first<<endl<<it->second<<endl;
		cout<<endl;
	}
	return 0;
}