#include <iostream>
#include <string>
#include <map>

#define mp make_pair

using namespace std;

int main(){
	map<string,int> stoint;
	stoint.insert(mp("000",0));stoint.insert(mp("001",1));
	stoint.insert(mp("010",2));stoint.insert(mp("011",3));
	stoint.insert(mp("100",4));stoint.insert(mp("101",5));
	stoint.insert(mp("110",6));stoint.insert(mp("111",7));
	int k,i,j,l,n,p,ip; scanf("%d", &k);
	for(i=0; i<k; ++i){
		scanf("%d %d", &n, &p);
		bool probarr[p] = {}; bool teams[n] = {}; int maxteams[n] = {};
		for(j=0; j<n; ++j){
			for(l=0; l<p; ++l){
				scanf("%d", &ip);
				probarr[l] |= ip;
				teams[j] |= ip;
				maxteams[j] += ip;
			}
		}
		bool probans = true;
		for(l=0; l<p; ++l)
			probans &= probarr[l];
		bool teamsans = true;
		for(j=0; j<n; ++j)
			teamsans &= teams[j];
		bool maxperteam = true;
		for(j=0; j<n; ++j)
			maxperteam &= (maxteams[j]<p);

		string ans = "";
		if(probans)
			ans += "1";
		else
			ans += "0";
		if(teamsans)
			ans += "1";
		else
			ans += "0";
		if(maxperteam)
			ans += "1";
		else
			ans += "0";

		printf("Case %d: %d\n", i+1, (stoint.find(ans))->second);
	}
	return 0;
}