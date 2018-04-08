// 1117
// idea is to use 2D grid dp
// index i indicates start of sub-group, index j indicates end of sub-group
// i.e. say arr[1][3] is subgroup 117 arr[2][3] is subgroup 17
// 0 is for number of possibilities, 1 is for sum of subgroup
// process from bottom to top, process from right to left
// for each entry, check all possible sub-groups to right starting from j+1 th
// index and if the sum is greater than current subgroup sum, add number of
// possiblities - hence process this too from right to left, can break earlier
// answer is sum of first row possibilities

#include <iostream>
#include <string>

using namespace std;

int main(){
	string ip; int count = 1;
	while(true){
		cin>>ip;
		if(ip == "bye")
			break;
		int len = ip.length();

		int arr[len][len][2] = {};
		arr[len-1][len-1][0] = 1; arr[len-1][len-1][1] = ip[len-1] - '0';

		// bottom to top
		for(int i=len-2; i>=0; --i){
			arr[i][len-1][0] = 1; arr[i][len-1][1] = arr[i+1][len-1][1] + ip[i] - '0';
			
			int sum = 0;
			for(int j=i; j<len; ++j)
				sum += (ip[j]-'0');

			// right to left
			for(int j=len-2; j>=i; --j){
				sum -= (ip[j+1] - '0');
				arr[i][j][1] = sum;

				// this too from right to left
				for(int k=len-1; k>=j+1; --k){
					if(arr[j+1][k][1] >= (arr[i][j][1])){
						arr[i][j][0] = arr[i][j][0] + arr[j+1][k][0];
					}
					else
						break;
				}
			}
		}

		// for(int i=0; i<len; ++i){
		// 	for(int j=0; j<len; ++j){
		// 		cout<<arr[i][j][0]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"--------"<<endl;
		// for(int i=0; i<len; ++i){
		// 	for(int j=0; j<len; ++j){
		// 		cout<<arr[i][j][1]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		int ans = 0;
		// sum of top row entries
		for(int i=0; i<len; ++i)
			ans += arr[0][i][0];
		printf("%d. %d\n", count++, ans);
		// cout<<endl;
	}
	return 0;
}