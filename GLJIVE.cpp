// cryptic way of stating the question

#include <iostream>

using namespace std;

int main(){
	int arr[10];
	int sum = 0;
	for(int i=0; i<10; ++i){
		scanf("%d", &arr[i]);
		if(abs(sum+arr[i]-100)<=abs(sum-100))
			sum+=arr[i];
		else
			break;
	}

	printf("%d\n", sum);
	return 0;
}