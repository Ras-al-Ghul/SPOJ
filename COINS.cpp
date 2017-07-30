// read question carefully - have to spot that it is dp or recursion

// unsignedint can hold upto (100,000,000 * 4) + some change

// first dp - feels good
// key is to find out optimal substructure
// also learned to use try catch here to handle failed inserts to map which results in bad_alloc

#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define ui unsigned int

using namespace std;

map<ui, ui> A;

ui valfind(ui val){
	auto it = A.find(val);
	if(it != A.end()){
		return it->second;
	}
	else{
		ui tempval = max((valfind((ui)(val/2))+valfind((ui)(val/3))+valfind((ui)(val/4))), val);
		try{
			A.insert(pair<ui, ui>(val, tempval));
			return tempval;
		}
		catch(const bad_alloc& e){
			return tempval;
		}
	}
}

int main(){
	ui coinval, sum;
	string val;
	
	A.insert(pair<ui, ui>(0, 0));
	while(getline(cin, val)){
		istringstream iss(val);
		iss>>coinval;
		printf("%u\n", valfind(coinval));
	}
	return 0;
}