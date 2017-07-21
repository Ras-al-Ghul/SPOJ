#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

int stringParse(string line, string& date){
	date = "hello";

	return 0;
}

int main(){

	string line;
	vector< tuple<int,int,int,int,int,int> > numbers;

	map<tuple<int,int,int,int,int,int>, string> mapping;
	// problems.insert(pair<string,string>("hi", "hello"));

	// for(map<string, string>::iterator it = problems.begin(); it != problems.end(); ++it){
	// 	cout<<it->first;
	// }

	string data;
	while(getline(cin, line)){
		stringstream iss(line);
		string data;
		int counter = 0;
		int year, month, date;
		tuple<int,int,int,int,int,int> sortbase;
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
				sortbase = tuple<int,int,int,int,int,int>
								(year,month,date,hour,minute,second);
				numbers.push_back(sortbase);
			}
			else{
				mapping.insert(pair<tuple<int,int,int,int,int,int>, string>(sortbase, data));
			}
			counter++;
		}
	}
	for(map<tuple<int,int,int,int,int,int>, string>::iterator it = mapping.begin();
		it != mapping.end(); ++it){
		cout<<get<0>(it->first)<<"-"<<get<1>(it->first)<<"-"<<get<2>(it->first)
		<<" "<<get<3>(it->first)<<":"<<get<4>(it->first)<<":"<<get<5>(it->first)
		<<" "<<it->second<<endl;
	}

	return 0;
}