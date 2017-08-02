// as usual be careful with test cases
// if problem looks easy, the deal is in handling all test cases
// being in a hurry and being stupid costed lot of WAs

#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main(){
	ll first, second, third;
	while(true){
		scanf("%lld %lld %lld", &first, &second, &third);
		if(first == 0 && second == 0 && third == 0)
			break;
		if(second >= first && third >= second){
			ll diff = second - first;
			if(diff == (third - second) and diff != 0){
				cout<<"AP "<<third+diff<<endl;
				continue;
			}
		}
		else if(second <= first and third <= second){
			ll diff = first - second;
			if(diff == (second - third) and diff != 0){
				cout<<"AP "<<third-diff<<endl;
				continue;
			}
		}
		//it is GP, handle all cases
		if(second==0 or third==0){
			cout<<"GP "<<0<<endl;
			continue;
		}
		ll cr;
		if(abs(third) > abs(first)){
			cr = sqrt(abs(third/first));
			ll negcount = 0;
			if(first < 0)
				negcount += 1;
			if(second < 0)
				negcount += 1;
			if(third < 0)
				negcount += 1;
			if(negcount==2 or negcount==1)
				cr = -cr;
			cout<<"GP "<<third*cr<<endl;
		}
		else{
			cr = sqrt(abs(first/third));
			ll negcount = 0;
			if(first < 0)
				negcount += 1;
			if(second < 0)
				negcount += 1;
			if(third < 0)
				negcount += 1;
			if(negcount==2 or negcount==1)
				cr = -cr;
			cout<<"GP "<<third/cr<<endl;
		}
	}
	return 0;
}