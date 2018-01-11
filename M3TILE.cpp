// top down was working perfect
// <https://www.quora.com/Can-somebody-explain-solution-to-SPOJ-com-Problem-M3TILE>

#include <iostream>
#include <cstring>

using namespace std;

int temp;

int dp(int index, int top, int mid, int bot, int arr[31][3][3][3]){
	if(index == temp-1){
		if(top == 0 or bot == 0)
			return 0;
		else{
			return 1;
		}
	}

	if(index!=-1 and arr[index][top][mid][bot] != 0){
		return arr[index][top][mid][bot];
	}

	int sum = 0;
	if(top == 0){
		if(mid != 0){
			sum += dp(index+1, 2, 0, 0, arr);
			sum += dp(index+1, 2, 1, 1, arr);
		}
		else{
			if(bot == 0)
				sum += dp(index+1, 2, 2, 2, arr);
			else
				sum += dp(index+1, 2, 2, 0, arr);
		}
	}
	else if(top == 1){
		if(bot == 0){
			sum += dp(index+1, 0, 0, 2, arr);
			sum += dp(index+1, 1, 1, 2, arr);
		}
		else{
			sum += dp(index+1, 0, 1, 1, arr);
			sum += dp(index+1, 0, 0, 0, arr);
			sum += dp(index+1, 1, 1, 0, arr);
		}
	}
	else{
		if(mid == 0){
			sum += dp(index+1, 0, 2, 2, arr);
		}
		else if(mid == 2){
			if(bot == 2){
				sum += dp(index+1, 0, 1, 1, arr);
				sum += dp(index+1, 0, 0, 0, arr);
				sum += dp(index+1, 1, 1, 0, arr);	
			}
			else{
				sum += dp(index+1, 0, 0, 2, arr);
				sum += dp(index+1, 1, 1, 2, arr);
			}
		}
		else{
			sum += dp(index+1, 0, 1, 1, arr);
			sum += dp(index+1, 0, 0, 0, arr);
			sum += dp(index+1, 1, 1, 0, arr);
		}
	}
	if(index != -1)
		return arr[index][top][mid][bot] = sum;
	else
		return sum;
}

int main(){
	int n, T[31], F[31];
	T[0]=1; F[0]=0;
	//memoise the values first
	for(int i=1; i<=30; i++){
		T[i] = ((i>=2)?3*T[i-2]:0) + ((i>=3)?2*F[i-3]:0);
		F[i] = T[i-1] + ((i>=2)?F[i-2]:0);
	}
	while(true){
		scanf("%d", &temp);
		if(temp == -1)
			break;
		// int arr[31][3][3][3] = {};
		// printf("%d\n", dp(-1,2,2,2,arr));
		printf("%d\n", T[temp]);
	}
	return 0;
}