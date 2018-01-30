#include <iostream>
#include <set>
#include <cmath>
#include <climits>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

inline int gcd(int a, int b){
	int temp;
	if(a<b)
		temp = a, a = b, b = temp;
	while(b != 0)
		temp = b, b = a%b, a = temp;
	return a;
}

int main(){
	int n;
	while(true){
		set<pii > dup;
		scanf("%d", &n);
		if(n==0)
			break;
		int arr[n][2];
		for(int i=0; i<n; ++i)
			scanf("%d %d", &arr[i][0], &arr[i][1]);
		
		int x, y, temp;
		bool flag;
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				flag = false;
				y = arr[j][1] - arr[i][1];
				flag = y<0?true:false;
				x = arr[j][0] - arr[i][0];
				flag = x<0?!flag:flag;
				temp = gcd(abs(x), abs(y));
				x = abs(x)/temp; y = abs(y)/temp;
				if(flag)
					y = -y;
				if(x == 0 or y == 0){
					if(x == 0)
						y = INT_MAX;
					else if(y == 0)
						x = 0;
				}
				if(dup.find(mp(x, y)) == dup.end())
					dup.insert(mp(x, y));
			}
		}
		printf("%lu\n", dup.size());
	}
	return 0;
}