#include <iostream>
#include <string>
#include <map>

using namespace std;

bool compare(int i, int j){
	return i < j;
}

// index, value, fenwick tree, size of fenwick tree
void update(int i, int v, int a[], int alen) {
    while (i < alen){
    	a[i] += v;
    	i |= i + 1;
    }
}
// index, fenwick tree
int prefixsum(int n, int a[]){
    int sum = 0;
    while (n > 0){
    	sum += a[n - 1];
    	n &= n - 1;
    }
    return sum;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		map<string,int> indices; string ip;
		for(int i=0; i<n; ++i){
			cin>>ip;
			indices[ip] = i+1;
		}
		int arr[n];
		for(int i=0; i<n; ++i){
			cin>>ip;
			arr[i] = indices[ip];
		}
		// copied from INVCNT
		int invcnt = 0;
		int fenwick[n] = {};
		for(int i=n-1; i>=0; --i){
			invcnt += prefixsum(arr[i], fenwick);
			update(arr[i], 1, fenwick, n);
		}
		printf("%d\n", invcnt);
	}
	return 0;
}