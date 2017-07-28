// algorithm has reverse() which will reverse almost anything
// stoi and to_string are C++ standards

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int numoftestcases;
	scanf("%d", &numoftestcases);
	string firstnum, secondnum;
	int firstnumrev, secondnumrev;

	while(numoftestcases--){
		cin>>firstnum>>secondnum;
		reverse(firstnum.begin(), firstnum.end());
		firstnumrev = stoi(firstnum);
		reverse(secondnum.begin(), secondnum.end());
		secondnumrev = stoi(secondnum);
		firstnumrev += secondnumrev;
		while(firstnumrev%10 == 0){
			firstnumrev /= 10;
		}
		firstnum = to_string(firstnumrev);
		reverse(firstnum.begin(), firstnum.end());
		cout<<firstnum<<endl;
	}

	return 0;
}