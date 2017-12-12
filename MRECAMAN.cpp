// brute force sequence

#include <iostream>
#include <set>

using namespace std;

int main(){
	long num;
	long arr[500001];
	set<long> recaman;
	arr[0] = 0;
	recaman.insert(0);
	for(long i=1; i<500001; ++i){
		long temp = arr[i-1] - i;
		if(temp > 0 and recaman.find(temp) == recaman.end()){
			arr[i] = temp;
			recaman.insert(temp);
		}
		else{
			arr[i] = arr[i-1] + i;
			recaman.insert(arr[i]);
		}
	}
	while(true){
		scanf("%ld", &num);
		if(num == -1)
			break;
		cout<<arr[num]<<endl;
	}
	return 0;
}