#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		int arr[n];
		for(int i=0; i<n; ++i){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		bool flag = false;
		for(int i=1; i<n; ++i){
			if(arr[i] - arr[i-1] > 200){
				flag = true;
				break;
			}
		}
		if((1422-arr[n-1])*2 > 200)
			flag = true;
		if(not flag)
			cout<<"POSSIBLE"<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}