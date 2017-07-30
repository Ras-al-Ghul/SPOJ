// very important thing learnt
// be very careful while using iterators on vectors of fixed length -
// which you've given initially like vector<ull> firstrow(100)

// scanf works perfectly fine for reading space separated integers from same line
// no need of getline, etc.

// also sometimes better to directly sort than using fancy structures like heap if it is overkill

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#define ull unsigned long long
#define MAXSIZE 1005
#define pb push_back

using namespace std;

int main(){
	int numoftestcases;
	scanf("%d", &numoftestcases);

	int matches;

	vector<ull> firstrow;
	vector<ull> secondrow;
	ull temp;

	ull sum;

	string line;
	while(numoftestcases--){
		scanf("%d", &matches);

		getline(cin, line);
		getline(cin, line);

		istringstream iss(line);

		for(int i=0; i<matches; i++){
			iss>>temp;
			firstrow.pb(temp);
		}

		getline(cin, line);
		istringstream isss(line);
		sum = 0;
		for(int i=0; i<matches; i++){
			isss>>temp;
			secondrow.pb(temp);
		}

		make_heap(firstrow.begin(), firstrow.end());
		make_heap(secondrow.begin(), secondrow.end());

		for(int i=0; i<matches; i++){
			sum += (firstrow.front() * secondrow.front());
			// cout<<firstrow.front()<<" "<<secondrow.front()<<endl;
			pop_heap(firstrow.begin(), firstrow.end());
			firstrow.pop_back();
			pop_heap(secondrow.begin(), secondrow.end());
			secondrow.pop_back();
		}

		printf("%llu\n", sum);
	}

	return 0;
}