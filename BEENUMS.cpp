// don't know if hash table gives better look up speed than set
// is there an stl hash table?

#include <iostream>
#include <set>

#define ll long long
#define MAX 1000000000

using namespace std;

int main(){
	set<ll> beenums;
	ll i=0, num = 1;
	while(num<=MAX){
		beenums.insert(num);
		num = num + (6+(i*6));
		++i;
	}
	while(true){
		scanf("%lld", &num);
		if(num == -1)
			break;
		if(beenums.find(num) != beenums.end())
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	
	return 0;
}
