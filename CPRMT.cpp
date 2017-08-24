// what a twisted problem statement
// just need to print common characters in ascending order
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string one, two;
	int i,j;
	while(getline(cin, one)){
		getline(cin, two);
		int oneset[26] = {0}, twoset[26] = {0};
		for(i=0;i<one.length();i++)
			oneset[one[i] - 'a']++;
		for(i=0;i<two.length();i++)
			twoset[two[i] - 'a']++;
		for(i=0;i<26;i++){
			oneset[i]=min(oneset[i],twoset[i]);
			if(oneset[i] != 0){
				for(j=0;j<oneset[i];j++){
					cout<<char(int('a')+i);
				}
			}
		}
		cout<<endl;
	}

	return 0;
}