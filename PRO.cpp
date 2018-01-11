// multiset vs. two heaps - one min and one max

#include <iostream>
#include <set>
#include <iterator>

#define ll long long

using namespace std;

int main(){
	ll days;
	scanf("%lld", &days);

	multiset<ll> box;
	ll sum = 0;

	ll nbills, temp;
	while(days--){
		scanf("%lld", &nbills);
		while(nbills--){
			scanf("%lld", &temp);
			box.insert(temp);
		}
		auto it1 = box.begin();
		auto it2 = prev(box.end());
		sum += ((*it2)-(*it1));
		box.erase(it1);box.erase(it2);
	}
	printf("%lld\n", sum);
	return 0;
}