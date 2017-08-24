// https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/
// interesting idea - can use binary-search for real valued functions too

// look if the predicate holds given a sorted list, to decide if binary search can be used or not

// initialize low and high properly - here it is the value of the min distance which has to be maximized

// min max, max min kind of problems

// low < high because low == high is exit condition

// mid is the actual value we're looking for

// another important thing is low + (high-low)/2 for handling negative numbers too

// another important thing is mid = low + (high-low)/2 might be equal to low due to rounding down,
// in which case, we will get stuck becuase low = mid --> low = low.
// Therefore if (mid == low), mid = mid + 1

// reqd < ncows vs. reqd <= ncows, where to hand '=' case - in if or in else

// for deciding low = mid or mid + 1 and high = mid or mid-1,
// see if mid will still be a part of the solution in next iteration,
// if yes, then it is = mid, else it is = mid-1 or = mid+1

// #include iterator while using prev and next
// using sets here might not be a good idea - next() and prev() maybe O(n)


#include <iostream>
#include <set>
#include <iterator>

#define ll long long

using namespace std;

int main(){
	ll ncases;
	scanf("%lld", &ncases);
	ll nstalls, ncows, i, temp, low, high, mid, reqd, prevval, endval;
	set<ll> stalls; set<ll>::iterator iter;
	while(ncases--){
		scanf("%lld %lld", &nstalls, &ncows);
		
		for(i=0; i<nstalls; i++){
			scanf("%lld", &temp);stalls.insert(temp);
		}

		low = 1; high = (*prev(stalls.end())) - (*stalls.begin());
		i = 0;
		while(low<high){
			mid = low + (high-low)/2;
			if(mid==low){
				mid += 1;
			}
			reqd = 2;
			prevval = *(stalls.begin());
			endval = *(prev(stalls.end()));
			for(iter=next(stalls.begin());iter!=prev(stalls.end());iter++){
				while(min((*iter)-prevval, endval-(*iter))<mid && iter!= prev(stalls.end())){
					iter++;
				}
				if(iter == prev(stalls.end()))
					break;
				prevval = (*iter);
				reqd++;
			}
			if(reqd<ncows){
				high = mid-1;
			}
			else{
				low = mid;
			}
		}
		cout<<low<<endl;
		stalls.clear();
	}
	return 0;
}