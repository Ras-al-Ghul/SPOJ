// similar to AGGRCOW, except process from the last and use 'high' instead of 'low'
// also no need of if(mid==high) mid -= 1; because division will round down, not up
// also sort(arr, arr+m) is causing problems
// obviously it won't work such a stupid question
// we're trying to assign books for given order, not for sorted order

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long ncases;
	scanf("%lld", &ncases);
	while(ncases--){
		long long m, k;
		scanf("%lld %lld", &m, &k);
		long long arr[m];
		long long unsortedarr[m];
		
		long high = 0;

		for(long long i=0; i<m; ++i){
			scanf("%lld", &arr[i]);
			high+=arr[i];
			unsortedarr[i] = arr[i];
		}
		// sort(arr, arr+m);

		long long low = 0, mid, temp;

		while(low < high){
			mid = low + ((high-low)/2);
			// if(mid == high)
			// 	mid -= 1;
			
			// have to greedily assign atmax mid pages to each scribe
			temp = mid;
			long long each[k] = {};
			long long ecount = k-1;
			bool flag = false;
			for(long long i=m-1; i>=0; --i){
				if(temp - arr[i] >= 0){
					temp -= arr[i];
					each[ecount] += 1;
				}
				else{
					if(each[ecount] == 0){
						flag = true;
						break;
					}
					else{
						if(ecount-1 >= 0){
							each[--ecount] += 1;
							if(mid - arr[i] >= 0)
								temp = mid - arr[i];
							else{
								flag = true;
								break;
							}
						}
						else{
							flag = true;
							break;
						}
					}
				}
			}
			if(flag){
				low = mid + 1;
			}
			else{
				high = mid;
			}
		}
		long long eachfinal[k] = {};
		long long ecount = k-1;
		long long avail = m-1;
		while(ecount >= 0){
			if(avail>=ecount and (eachfinal[ecount]+unsortedarr[avail]) <= high){
				eachfinal[ecount] += unsortedarr[avail];
				--avail;
			}
			else{
				--ecount;
			}
		}

		long long book = 0;
		for(long long i=0; i<k; ++i){
			while(unsortedarr[book]<=eachfinal[i] and book < m){
				if(book != m-1)
					printf("%lld ", unsortedarr[book]);
				else
					printf("%lld", unsortedarr[book]);
				eachfinal[i] -= unsortedarr[book];
				++book;
			}
			if(i != k-1){
				printf("/ ");
			}
		}
		printf("\n");
	}
	return 0;
}