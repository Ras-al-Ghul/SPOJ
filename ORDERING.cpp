// the goal was to sort Anudeep's SPOJ order, there might be some mystery
// thought I'd use Python for this, but using C++ actually turned out to be an amazing learning experience

// read from getline needs stringstream (sstream) and string to which it will read to, also it can use separator to separate things in the stringstream
// better to use typedef for repeated stuff
// used vector of tuples and map of <tuple, string>

// outer variable with same variable name as inner is scoped out and cannot be accessed even using namespace

// push_back for vectors, insert for map
// create pair for inserting into map

// iterator of required type

// access elements of pair using ->
// access elements of tuple using get<i>(tuple)

// best part was that the map automatically sorted based on the key - which was a tuple - precedence left to right

#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

int main(){

	string line;
	typedef tuple<int,int,int,int,int,int> hexint;

	vector< hexint > numbers;

	map< hexint , string> mapping;

	string data;
	while(getline(cin, line)){
		stringstream iss(line);
		string data;
		int counter = 0;
		int year, month, date;
		hexint sortbase;
		while(getline(iss, data, ' ')){
			if(counter == 0){
				stringstream dates(data);
				string individuals;
				int innercount = 0;
				while(getline(dates, individuals, '-')){
					switch(innercount){
						case 0:
							year = stoi(individuals);
						case 1:
							month = stoi(individuals);
						case 2:
							date = stoi(individuals);
					}
					innercount++;
				}
			}
			else if(counter == 1){
				int hour, minute, second;
				stringstream times(data);
				string individuals;
				int innercount = 0;
				while(getline(times, individuals, ':')){
					switch(innercount){
						case 0:
							hour = stoi(individuals);
						case 1:
							minute = stoi(individuals);
						case 2:
							second = stoi(individuals);
					}
					innercount++;
				}
				sortbase = hexint(year,month,date,hour,minute,second);
				numbers.push_back(sortbase);
			}
			else{
				mapping.insert(pair<hexint, string>(sortbase, data));
			}
			counter++;
		}
	}
	for(map<hexint, string>::iterator it = mapping.begin();
		it != mapping.end(); ++it){
		cout<<get<0>(it->first)<<"-"<<get<1>(it->first)<<"-"<<get<2>(it->first)
		<<" "<<get<3>(it->first)<<":"<<get<4>(it->first)<<":"<<get<5>(it->first)
		<<" "<<it->second<<endl;
	}

	return 0;
}