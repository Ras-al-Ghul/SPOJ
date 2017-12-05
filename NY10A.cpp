// Does product NFA apply here?
// Generalizing might be the real challenge

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	int P, casenum;
	scanf("%d", &P);
	string sequence;
	while(P--){
		scanf("%d", &casenum);
		cin>>sequence;
		map<string, int> counter;
		counter["TTT"] = 0; counter["TTH"] = 0; counter["THT"] = 0; counter["THH"] = 0;
		counter["HTT"] = 0; counter["HTH"] = 0; counter["HHT"] = 0; counter["HHH"] = 0;

		string first = "",second = "",third = "";
		for(int i=0;i<40;++i){
			if(first == ""){
				first += sequence[i];

				if(second != ""){
					second += sequence[i];

					counter[second] += 1;
					second = "";
				}
				if(third != ""){
					third += sequence[i];
				}
			}
			else if(second == "" and first.length() == 1){
				second += sequence[i];
				first += sequence[i];

				if(third != ""){
					third += sequence[i];

					counter[third] += 1;
					third = "";
				}
			}
			else if(third == "" and second.length() == 1){
				third += sequence[i];
				second += sequence[i];
				first += sequence[i];

				counter[first] += 1;
				first = "";
			}
		}
		printf("%d %d %d %d %d %d %d %d %d\n", casenum, counter["TTT"], counter["TTH"], counter["THT"], counter["THH"],
		counter["HTT"], counter["HTH"], counter["HHT"], counter["HHH"]);
	}

	return 0;
}