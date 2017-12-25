#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	string t1, t2, t; int g1, g2;
	while(ncases--){
		map<string, int> results;
		string winner = "";
		for(int i=0; i<16; ++i){
			cin>>t1>>t2>>g1>>g2;
			if(g1>g2)
				t = t1;
			else
				t = t2;
			auto it = results.find(t);
			if(it != results.end()){
				it->second++;
				if(it->second == 4){
					winner = it->first;
				}
			}
			else
				results.insert(pair<string,int>(t,1));
		}
		cout<<winner<<endl;
	}
	return 0;
}