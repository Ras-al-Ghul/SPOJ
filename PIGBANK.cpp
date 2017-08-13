// bottom up dp
// taught a few things
// if algo doesn't feel right, then it probably isn't right - for eg. top down dp in this case
// too many edge cases to handle in my first approach, finally got onto the correct approach
// when is it the optimal substructure - very important
// checking all special cases
// duplicate keys - possible or not
// what is chosen as key, what is value

#include <iostream>
#include <map>
#include <climits>

#define ll long long

using namespace std;

map<ll, ll> A;
map<ll, ll> C;

int main(){
	ll ncases;
	scanf("%lld", &ncases);
	ll empty, weight;
	ll numofcoins, coinval, coinw;
	ll i, fir, sec;
	while(ncases--){
		scanf("%lld %lld", &empty, &weight);
		weight -= empty;
		scanf("%lld", &numofcoins);

		if(weight==0){
			cout<<"The minimum amount of money in the piggy-bank is "<<0<<"."<<endl;
			continue;
		}

		while(numofcoins--){
			scanf("%lld %lld", &coinval, &coinw);
			if(C.find(coinw) == C.end())
				C.insert(pair<ll, ll>(coinw, coinval));
			else{
				if(C.find(coinw)->second > coinval)
					C[coinw] = coinval;
			}
		}

		A.insert(pair<ll, ll>(0, 0));
		for(i = 1; i <= weight; i++){
			ll min = LLONG_MAX, minwt;
			for(auto iter=C.begin(); iter != C.end(); iter++){
				fir = (iter->first);
				if(i >= fir){
					sec = i - fir;
					if(A.find(sec) != A.end()){
						if(A.find(sec)->second + iter->second < min){
							minwt = fir;
							min = A.find(sec)->second + iter->second;
						}
					}
				}
			}
			if(min != LLONG_MAX){
				A.insert(pair<ll, ll>(i, min));
				continue;
			}
		}
		if(A.find(weight) != A.end()){
			cout<<"The minimum amount of money in the piggy-bank is "<<A.find(weight)->second<<"."<<endl;
		}
		else{
			cout<<"This is impossible."<<endl;
		}

		A.clear();
		C.clear();
	}
	return 0;
}