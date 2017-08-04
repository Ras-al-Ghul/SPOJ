// a pretty good dynamic programming soln - not fully working
// game theory class example sufficed in the end

// lesson learned - look at decrease in size of function while using recursion
// if sufficient size decrease not got, that means, it will run out of stack size
// better solution needed

#include <iostream>
#include <string>
// #include <cstring>
// #include <map>

#define ll long long

using namespace std;

// typedef map<ll, int[2]> maps;
// maps mymap;

// ll globalval;

// flip == 1 for Nikifor, 0 for Trofim
// success for Nikifor is 1, failure is 0
// char 0 is 1 - 1 for Nikifor, 0 for Trofim - who had played move
// char 1 is 1 for Nikifor success, 0 for Trofim success
// int recurse(ll val, int flip){
// 	cout<<mymap.size()<<" ";
// 	maps::iterator it = mymap.find(val);
// 	if(it != mymap.end()){
// 		// Nikifor had played the move and he succeeded or failed
// 		if(flip and it->second[0])
// 			if(it->second[1])
// 				return 1;
// 			else
// 				return 0;
// 		else if(flip and !it->second[0])
// 			if(it->second[1])
// 				return 0;
// 			else
// 				return 1;
// 		else if(!flip and it->second[0])
// 			if(it->second[1])
// 				return 0;
// 			else
// 				return 1;
// 		else if(!flip and !it->second[0])
// 			if(it->second[1])
// 				return 1;
// 			else
// 				return 0;
// 	}
// 	if(val <= 0){
// 		if(flip){
// 			mymap[0][0] = 1, mymap[0][1] = 1;
// 			return 1;
// 		}
// 		else{
// 			mymap[0][0] = 0, mymap[0][1] = 0;
// 			return 0;
// 		}
// 	}

// 	ll dupval = val, max = 0;
// 	bool flag = false;
// 	while(dupval/10 != 0){
// 		if(dupval%10 != 0){
// 			if(recurse(val - (dupval%10), (flip+1)%2)){
// 				max = 1;
// 				flag = true;
// 				break;
// 			}
// 		}
// 		dupval/=10;
// 	}
// 	if(!flag){
// 		if(recurse(val - (dupval%10), (flip+1)%2)){
// 			max = 1;
// 			flag = true;
// 		}
// 	}
// 	if(flag){
// 		try{
// 			mymap[val][0] = flip, mymap[val][1] = 1;
// 		}
// 		catch(exception &e){

// 		}
// 		if(val == globalval)
// 			return dupval%10;
// 		else
// 			return 1;
// 	}
// 	else{
// 		try{
// 			mymap[val][0] = flip, mymap[val][1] = 0;
// 		}
// 		catch(exception &e){

// 		}
// 		return 0;
// 	}
// }

// int main(){
// 	ll ip, op;
// 	string line;
// 	while(getline(cin, line)){
// 		ip = stoll(line);
// 		globalval = ip;
// 		op = recurse(ip, 0);
// 		if(op > 0)
// 			cout<<1<<endl<<op<<endl;
// 		else
// 			cout<<2<<endl;
// 		mymap.clear();
// 	}

// 	return 0;
// }

int main()
{
	ll ip, tempval;
	string line;
	while(getline(cin, line)){
		ip = stoll(line);
		tempval = ip;
		bool flag = false;
		while(tempval/10 != 0){
			if(!((ip - (tempval%10))%10) and (tempval%10)){
				cout<<1<<endl<<tempval%10<<endl;
				flag = true;
				break;
			}
			tempval/=10;
		}
		if(!flag){
			if(!((ip - (tempval%10))%10)){
				cout<<1<<tempval%10<<endl;
				flag = true;
			}
		}
		if(!flag){
			cout<<2<<endl;
		}
	}
	return 0;
}