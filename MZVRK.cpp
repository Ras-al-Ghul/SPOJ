// my approach was based on subtracting relevant powers of 2 from (n(n+1))/2
// c++ was overflowing, hence used python
// simpler solutions exist:
// My approach was the following:
// - think that for each number, the Whirligig is the smallest power of two that divides it
// - there must be a clear pattern for the Whirligigs and it is related to the power of 2s
// - for each integer between 1 and 128, print the Whirligig number and the sum of Whirligig numbers up to
// - find the pattern and the way to calculate the result efficiently

// obviously, if subtracting logic works, adding will work too

#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

#define ll unsigned long long

using namespace std;

int main(){
	ll a, b, temp; scanf("%llu %llu", &a, &b);
	// a is smaller
	if(a>b){
		temp = a; a = b; b = temp;
	}
	string bin_a = bitset<64>(a).to_string();
	string bin_b = bitset<64>(b).to_string();

	// cout<<bin_a<<endl<<bin_b<<endl;
	ll ans = ((b*(b+1))/2) - (((a-1)*a)/2);
	// cout<<a<<" "<<b<<" "<<ans<<endl;

	ll size = b-a+1;
	ll left_a = log2(a);
	ll left_b = log2(b);

	ll times = 0, cycle_len, state, cur;
	ll cur_pow_2 = 2;
	// cout<<left_a<<" "<<left_b<<" "<<ans<<endl<<endl;
	for(ll i=62; i>=(64-left_b-1); --i){
		ll sum = 0, times = 0;
		cycle_len = cur_pow_2*2;
		state = 0;
		temp = cur_pow_2;
		for(ll j=i; j<64; ++j){
			state += (((ll)(bin_a[j])-48)*temp);
			temp/=2;
		}
		// cout<<cur_pow_2<<" "<<state<<endl;
		if(state <= cur_pow_2){
			// cout<<"if"<<endl;
			cur = cur_pow_2 - state + 1 + 1;
			if(cur <= size){
				times = min(size, cur+cur_pow_2-1-1) - cur + 1;
				ans -= (cur_pow_2*times);
				sum += (cur_pow_2*times);
			}
		}
		else{
			times = cycle_len-state;
			if(times > size){
				times = size;
			}
			ans -= (cur_pow_2*times);
			sum += (cur_pow_2*times);
		}
		// cout<<"times "<<times<<" "<<sum<<endl;
		times = 0;
		cur = cycle_len-state+1;
		if(cur+cycle_len-1<=size){
			times = ((size-cur+1)/cycle_len)*(cur_pow_2-1);
			ans -= (cur_pow_2*times);
			sum += (cur_pow_2*times);
			cur += (cycle_len*((size-cur+1)/cycle_len));
		}
		// cout<<"times2 "<<times<<" "<<sum<<endl;
		// cout<<"cur "<<cur<<endl;
		times = 0;
		if(cur<=size){
			temp = size-cur+1;
			if(temp-1>cur_pow_2){
				times = temp-1 - cur_pow_2;
				ans -= (cur_pow_2*times);
				sum += (cur_pow_2*times);
			}
		}

		// cout<<cycle_len<<" "<<state<<" "<<cur<<" "<<times<<endl;
		// cout<<sum<<endl<<endl;
		cur_pow_2 *= 2;
	}
	printf("%llu\n", ans);
	return 0;
}