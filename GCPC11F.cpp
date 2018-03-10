#include <iostream>
#include <string>
#include <map>
#include <iterator>

#define mp make_pair

using namespace std;

int main(){
	int c; scanf("%d", &c);
	string s;
	getline(cin,s);
	while(c--){
		getline(cin,s);
		int arr[26] = {};
		for(int i=0; i<s.length(); ++i){
			if(s[i] != ' ')
				arr[s[i] - 65]++;
		}
		multimap<int, int> temp;
		for(int i=0; i<26; ++i){
			temp.insert(mp(arr[i],i));
		}
		if(prev(temp.end())->first == prev(prev(temp.end()))->first){
			printf("NOT POSSIBLE\n");
			continue;
		}
		int ans = (prev(temp.end())->second+1 - 5+26)%26;
		printf("%d ", ans);
		for(int i=0; i<s.length(); ++i){
			if(s[i] != ' ')
				printf("%c", ((s[i]+26-ans-65)%26)+65);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}