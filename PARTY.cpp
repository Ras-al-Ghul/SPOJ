// qsort not really needed because it is not really necessary that the ordering will help
// what is really necessary though is line 58 - 71
// for Achieve the highest possible fun level, and do not spend more money than is absolutely necessary
// so if two are same fun, then choose cheaper one

#include <iostream>
#include <map>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int compare(const void *aa, const void *bb){
	int *a = (int *)aa;
	int *b = (int *)bb;
	if(a[0]>b[0])
		return 0;
	else if(a[0] == b[0])
		if(a[1]<=b[1])
			return 0;
		else
			return 1;
	else
		return 1;
}

int budget, nparties;
typedef map<pii, pii> CUSTOM;
CUSTOM dicts;
CUSTOM::iterator iter;

pii recurse(int capacity, int index, const int arr[][2]){
	iter = dicts.find(pii(capacity, index));
	if(iter != dicts.end()){
		return iter->second;
	}

	if(capacity==0 or index==nparties){
		try{
			dicts.insert(pair<pii, pii>(pii(capacity, index), pii(0, 0)));
		}
		catch(const bad_alloc& e){}
		return pii(0, 0);
	}

	if(arr[index][1] > capacity){
		pii temp1 = recurse(capacity, index+1, arr);
		dicts.insert(pair<pii, pii>(pii(capacity, index), temp1));
		return temp1;
	}

	pii temppair = recurse(capacity - arr[index][1], index+1, arr);
	pii temp1 = pii(temppair.first + arr[index][0], temppair.second + arr[index][1]);
	pii temptemp1 = recurse(capacity, index+1, arr);
	if(temp1.first >= temptemp1.first){
		if(temp1.first == temptemp1.first){
			if(temp1.second < temptemp1.second){
				try{
					dicts.insert(pair<pii, pii>(pii(capacity, index), temp1));
				}
				catch(const bad_alloc& e){}
				return temp1;
			}
			else{
				try{
					dicts.insert(pair<pii, pii>(pii(capacity, index), temptemp1));
				}
				catch(const bad_alloc& e){}
				return temptemp1;	
			}
		}
		try{
			dicts.insert(pair<pii, pii>(pii(capacity, index), temp1));
		}
		catch(const bad_alloc& e){}
		return temp1;
	}
	else{
		try{
			dicts.insert(pair<pii, pii>(pii(capacity, index), temptemp1));
		}
		catch(const bad_alloc& e){}
		return temptemp1;
	}
}

int main(){
	int i;
	while(true){
		scanf("%d %d", &budget, &nparties);
		if(budget==0 and nparties==0)
			break;
		int arr[nparties][2];
		for(i=0; i<nparties; i++){
			scanf("%d %d", &arr[i][1], &arr[i][0]);
		}
		// qsort(arr[0], nparties, sizeof(arr[0]), compare);
		pii temppair = recurse(budget, 0, arr);
		cout<<temppair.second<<" "<<temppair.first<<endl;
		dicts.clear();
	}

	return 0;
}