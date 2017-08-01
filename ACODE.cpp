// bad edge case handling cost many WAs
// the thing is I was considering c[0] <= 2 and c[1] <= 6
// what I wanted was c[01] <= 26
// for what I was doing, 17 doesn't pass

// another thing was handling zeros in between and
// case where number > 2 is follwed by a zero

// look for single scan DP first instead of recurse DP
// single scan DP as in bottom up - see from start of string,
// keep incrementing counter
// <https://www.quora.com/ACODE-Spoj-problem-solution>

#include <iostream>
#include <string>
#include <map>

#define ull long long
#define p pair<string, long long>

using namespace std;

typedef map<string, ull> Map;
Map m;

ull recurse(string ip){
	ull ln = ip.length();
	if(ln == 1){
		if(ip != "0")
			return (ull)(1);
		else
			return (ull)(0);
	}
	if(ln == 2){
		ull twolen = stoll(ip);
		if(twolen > (ull)(26) || twolen <= (ull)(10) || twolen == (ull)(20))
			if(twolen != (ull)(0) and (ip[0] - '0') != 0)
				return (ull)(1);
			else
				return (ull)(0);
		else
			return (ull)(2);
	}

	Map::iterator it = m.find(ip);
	if(it != m.end()){
		return it->second;
	}
	else{
		string temp = ip;
		if(ip[0] - '0' == 0){
			try{
				m.insert(p(ip, 0));
				return (ull)(0);
			}
			catch(const bad_alloc& e){
				return (ull)(0);
			}
		}

		ull sum = 0;
		temp.erase(0,1);

		if(!(temp[0] - '0' == 0)){
			sum += recurse(temp);
		}
		if(((ip[0] - '0') <= 2 && (temp[0] - '0') <= 6) || ((ip[0] - '0') <= 1 && (temp[0] - '0') <= 9)){
			temp.erase(0,1);
			sum += recurse(temp);
		}
		try{
			m.insert(p(ip, sum));
			return sum;
		}
		catch(const bad_alloc& e){
			return sum;
		}
	}
}

int main(){
	string input;

	while(getline(cin, input)){
		if(input=="0")
			break;

		int zcount = 0, prev = input[0] - '0';
		bool flag = false;
		for(int i=1; i<input.length(); i++){
			if(input[i] - '0' == 0){
				zcount += 1;
				if(zcount == 2){
					cout<<0<<endl;
					flag = true;
					break;
				}
				if(prev > 2){
					cout<<0<<endl;
					flag = true;
					break;
				}
			}
			if(prev==0)
				zcount = 0;
			prev = input[i] - '0';
		}
		if(flag)
			continue;
		cout<<recurse(input)<<endl;

		m.clear();
	}

	return 0;
}